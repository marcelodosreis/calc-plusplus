#ifndef CLI_INPUT_HANDLER_H
#define CLI_INPUT_HANDLER_H

#include <string>
#include <iostream>
#include "BasicCLI.h"

class CLIInputHandler {
private:
    BasicCLI cli;

    void displayMenu() const {
        cli.setColor(BasicCLI::Color::CYAN);
        std::cout << "=============================================\n";
        cli.setColor(BasicCLI::Color::MAGENTA);
        std::cout << "           Calculadora Matemática           \n";
        cli.setColor(BasicCLI::Color::GREEN);
        std::cout << "            (Versão 1.0 - CLI)              \n";
        cli.setColor(BasicCLI::Color::CYAN);
        std::cout << "=============================================\n";
        cli.setColor(BasicCLI::Color::WHITE);

    }

public:
    void showMenu() const {
        displayMenu();
    }

    void clearScreen() {
        #ifdef _WIN32
            system("cls")
        #else
            system("clear");
        #endif
    }

    std::string getUserInput() const {
        std::string prompt = "Digite uma expressão matemática (ou 'sair' para encerrar): ";
        return cli.get(prompt);
    }

    void showOutput(const std::string& message, BasicCLI::Color color = BasicCLI::Color::RESET) const {
        cli.setColor(color);
        cli.log(message);
        cli.setColor(BasicCLI::Color::RESET);
    }

    bool checkExitCondition(const std::string& input) const {
        return input == "sair";
    }
};

#endif // CLI_INPUT_HANDLER_H
