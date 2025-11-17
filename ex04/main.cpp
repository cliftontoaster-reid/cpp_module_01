/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell@student.42nice.fr <lfiorell>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:05:34 by lfiorell@st       #+#    #+#             */
/*   Updated: 2025/11/17 11:42:33 by lfiorell@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void printUsage(const char *programName) {
  std::cout << "Usage: " << programName
            << " <filename> <string_to_replace> <replacement_string>"
            << std::endl;
}

int main(int argc, char const *argv[]) {
  if (argc != 4) {
    printUsage(argv[0]);
    return 22;
  }

  const std::string filename = argv[1];
  const std::string replace = filename + ".replace";
  const std::string fromStr = argv[2];
  const char *toStr = argv[3];
  std::string buffer;

  std::ifstream inputFile;
  std::ofstream outputFile;

  inputFile.open(filename.c_str());
  outputFile.open(replace.c_str());

  while (!inputFile.eof() && inputFile.good() && outputFile.good()) {
    if (!std::getline(inputFile, buffer))
      break;

    unsigned long pos;
    while ((pos = buffer.find(fromStr)) != std::string::npos) {
      buffer.erase(pos, fromStr.length());
      buffer.insert(pos, toStr);
    }

    outputFile << buffer << std::endl;
  }

  inputFile.close();
  outputFile.close();

  return 0;
}
