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

        if (!(tokens >> leftOperand)) {
            throw std::invalid_argument("Formato inválido. Esperando um número.");
        }
        
        IExpression* result = new INumber(leftOperand);
        
        while (tokens >> operation) {
            if (operation != '+' && operation != '-') {
                throw std::invalid_argument("Operador inválido. Apenas + e - são suportados.");
            }

            if (!(tokens >> rightOperand)) {
                throw std::invalid_argument("Formato inválido. Esperando um número após o operador.");
            }

            IExpression* right = new INumber(rightOperand);

            if (operation == '+') {
                result = new IAddition(result, right);
            } else if (operation == '-') {
                result = new ISubtraction(result, right);
            }
        }

        return result;
    }
};

#endif // EXPRESSION_PARSER_H
