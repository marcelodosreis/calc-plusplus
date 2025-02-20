#include <string>
#include "presentation/CLIInputHandler.h"
#include "application/ExpressionParser.h"
#include "application/List.h"

int main() {
    CLIInputHandler cliInputHandler;
    ExpressionParser expressionParser;
    List list;

    cliInputHandler.clearScreen();
    cliInputHandler.showMenu();

    while (true) {
        std::string userInput = cliInputHandler.getUserInput();

        if (cliInputHandler.checkExitCondition(userInput)) {
            cliInputHandler.showOutput("Encerrando o programa.", BasicCLI::Color::RED);
            break;
        }
        list.teste(userInput);

        // try {
        //     IExpression* expression = expressionParser.parse(userInput);
        //     double result = expression->evaluate();


        //     cliInputHandler.showOutput("Resultado: " + std::to_string(result), BasicCLI::Color::GREEN);
            
        //     delete expression;
        // } catch (const std::exception& e) {
        //     cliInputHandler.showOutput(std::string("Erro: ") + e.what(), BasicCLI::Color::RED);
        // }
    }

    cliInputHandler.clearScreen();
    return 0;
}
