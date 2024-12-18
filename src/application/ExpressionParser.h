#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <string>
#include <sstream>
#include <stdexcept>
#include "../domain/entities/Addition.h"
#include "../domain/entities/Subtraction.h"
#include "../domain/entities/Number.h"

class ExpressionParser {
public:
    IExpression* parse(const std::string& input) const {
        std::istringstream tokens(input);
        double leftOperand;
        char operation;
        double rightOperand;

        if (!(tokens >> leftOperand >> operation >> rightOperand)) {
            throw std::invalid_argument("Formato inválido. Use: <número> <operador> <número>");
        }

        IExpression* left = new INumber(leftOperand);
        IExpression* right = new INumber(rightOperand);

        switch (operation) {
            case '+':
                return new IAddition(left, right);
            case '-':
                return new ISubtraction(left, right);
            default:
                throw std::invalid_argument("Operador inválido. Apenas + e - são suportados.");
        }
    }
};

#endif // EXPRESSION_PARSER_H
