#include <fstream>
#include <iostream>

#define BUFFER_SIZE 1024

static void printUsage(const char *prog) {
  std::cerr << "Usage: " << prog << " <file> <from string> <to string>"
            << std::endl;
}

// Open input and output streams. Returns true on success.
static bool openFiles(const std::string &file, std::ifstream &in,
                      std::ofstream &out) {
  in.open(file.c_str());
  if (!in) {
    std::cerr << "Error: Could not open input file." << std::endl;
    return false;
  }
  out.open((file + ".replace").c_str());
  if (!out) {
    in.close();
    std::cerr << "Error: Could not open output file." << std::endl;
    return false;
  }
  return true;
}

// Copy input to output (used when `from` is empty)
static void copyStream(std::ifstream &in, std::ofstream &out) {
  char ibuffer[BUFFER_SIZE];
  while (in.read(ibuffer, BUFFER_SIZE) || in.gcount() > 0) {
    out.write(ibuffer, in.gcount());
  }
}

// Flush obuffer to output file
static void flushObuffer(std::ofstream &out, std::string &obuffer) {
  if (!obuffer.empty()) {
    out.write(obuffer.c_str(), obuffer.size());
    obuffer.clear();
  }
}

// Process a chunk (with optional carry prepended) and update obuffer and new
// carry. This encapsulates the search/replace loop used while streaming.
static void processChunk(const std::string &chunk, const std::string &from,
                         const std::string &to, std::string &obuffer,
                         std::string &carry, std::ofstream &out) {
  size_t from_len = from.size();
  size_t i = 0;
  while (i < chunk.size()) {
    size_t remaining = chunk.size() - i;
    if (remaining >= from_len) {
      bool match = true;
      for (size_t k = 0; k < from_len; ++k) {
        if (chunk[i + k] != from[k]) {
          match = false;
          break;
        }
      }
      if (match) {
        obuffer.append(to);
        i += from_len;
      } else {
        obuffer.push_back(chunk[i]);
        ++i;
      }
    } else {
      break; // leave remainder for carry
    }

    if (obuffer.size() >= BUFFER_SIZE) {
      flushObuffer(out, obuffer);
    }
  }

  // build new carry from tail of chunk: up to from_len - 1 characters
  carry.clear();
  size_t tail_start = (i < chunk.size()) ? i : chunk.size();
  size_t carry_len =
      std::min(from_len > 0 ? from_len - 1 : 0, chunk.size() - tail_start);
  if (carry_len > 0) {
    carry.append(chunk.data() + tail_start, carry_len);
  }
}

int main(int argc, char const *argv[]) {
  if (argc != 4) {
    printUsage(argv[0]);
    return 1;
  }

  std::string file = argv[1];
  std::string from = argv[2];
  std::string to = argv[3];

  std::ifstream inputFile;
  std::ofstream outputFile;
  if (!openFiles(file, inputFile, outputFile))
    return 1;

  // Working buffers
  char ibuffer[BUFFER_SIZE];
  std::string obuffer;
  obuffer.reserve(BUFFER_SIZE);

  size_t from_len = from.size();

  if (from_len == 0) {
    copyStream(inputFile, outputFile);
    return 0;
  }

  std::string carry;

  while (inputFile.read(ibuffer, BUFFER_SIZE) || inputFile.gcount() > 0) {
    std::streamsize n = inputFile.gcount();
    std::string chunk;
    chunk.reserve(carry.size() + n);
    if (!carry.empty())
      chunk += carry;
    chunk.append(ibuffer, static_cast<size_t>(n));

    processChunk(chunk, from, to, obuffer, carry, outputFile);
  }

  // Process remaining carry after EOF
  if (!carry.empty()) {
    std::string tail = carry;
    // Reuse processChunk but since there's no more input, we can process tail
    // fully: if remaining < from_len, processChunk will leave it as carry, so
    // handle explicitly here to flush the remainder.
    size_t i = 0;
    while (i < tail.size()) {
      size_t remaining = tail.size() - i;
      if (remaining >= from_len) {
        bool match = true;
        for (size_t k = 0; k < from_len; ++k) {
          if (tail[i + k] != from[k]) {
            match = false;
            break;
          }
        }
        if (match) {
          obuffer.append(to);
          i += from_len;
        } else {
          obuffer.push_back(tail[i]);
          ++i;
        }
      } else {
        obuffer.append(tail.data() + i, remaining);
        break;
      }
      if (obuffer.size() >= BUFFER_SIZE) {
        flushObuffer(outputFile, obuffer);
      }
    }
  }

  flushObuffer(outputFile, obuffer);

  inputFile.close();
  outputFile.close();
  return 0;
}
