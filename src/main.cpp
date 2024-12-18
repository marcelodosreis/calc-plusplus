#include <string>

#include "presentation/CLIInputHandler.h"

#include "application/ExpressionParser.h"


int main() {
    CLIInputHandler cliInputHandler;
    ExpressionParser expressionParser;

    while (true) {
        std::string userInput = cliInputHandler.getUserInput();

        if (userInput == "sair") {
            cliInputHandler.showOutput("Encerrando o programa.");
            break;
        }

        try {
            IExpression* expression = expressionParser.parse(userInput);
            double result = expression->evaluate();

            cliInputHandler.showOutput("Resultado: " + std::to_string(result));
            
            delete expression;
        } catch (const std::exception& e) {
            cliInputHandler.showOutput(std::string("Erro: ") + e.what());
        }
    }

    return 0;
}