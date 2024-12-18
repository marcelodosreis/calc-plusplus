#ifndef CLI_INPUT_HANDLER_H
#define CLI_INPUT_HANDLER_H

#include <string>
#include <iostream>

class CLIInputHandler {
public:
    std::string getUserInput() const {
        std::string input;
        std::cout << "Digite uma expressão matemática (ou 'sair' para encerrar): ";
        std::getline(std::cin, input);
        return input;
    }

    void showOutput(const std::string& message) const {
        std::cout << message << std::endl;
    }
};

#endif // CLI_INPUT_HANDLER_H
