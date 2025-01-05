#ifndef BASIC_CLI_H
#define BASIC_CLI_H

#include <string>
#include <iostream>
#include <fstream>

class BasicCLI {
public:
    enum class Color {
        RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, RESET
    };

    void setColor(Color color) const {
        switch (color) {
            case Color::RED:
                std::cout << "\033[31m"; break;
            case Color::GREEN:
                std::cout << "\033[32m"; break;
            case Color::YELLOW:
                std::cout << "\033[33m"; break;
            case Color::BLUE:
                std::cout << "\033[34m"; break;
            case Color::MAGENTA:
                std::cout << "\033[35m"; break;
            case Color::CYAN:
                std::cout << "\033[36m"; break;
            case Color::WHITE:
                std::cout << "\033[37m"; break;
            case Color::RESET:
                std::cout << "\033[0m"; break;
        }
    }

    std::string get(const std::string& prompt) const {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        return input;
    }

    void log(const std::string& message) const {
        std::cout << message << std::endl;
    }
};

#endif // BASIC_CLI_H
