#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv){
    Harl harl;

    if (argc == 2){
        harl.complain(std::string(argv[1]));
        return 0;
    }

    std::cout << "Usage: ./harl <LEVEL>\n";
    std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR\n";
    std::cout << "Running sample tests...\n\n";

    std::string tests[] = {"DEBUG","INFO","WARNING","ERROR","SILLY"};
    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i){
        std::cout << "---- " << tests[i] << " ----" << std::endl;
        harl.complain(tests[i]);
        std::cout << std::endl;
    }

    return 0;
}

