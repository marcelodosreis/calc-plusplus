#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include "../domain/entities/Addition.h"
#include "../domain/entities/Number.h"
#include "../domain/entities/Subtraction.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class ExpressionParser {
public:
  IExpression *parse(const std::string &input) const {
    std::istringstream stream(input);
    double firstOperand;
    char operatorSymbol;
    double secondOperand;

    IExpression *result = new Number(firstOperand);
    int openParenthesesCount = 0;
    int closeParenthesesCount = 0;

    for (char ch : input) {
        if (ch == '(') {
            openParenthesesCount++;
        } else if (ch == ')') {
            closeParenthesesCount++;
        }
    }

    std::cout << "Parênteses de abertura '(': " << openParenthesesCount << std::endl;
    std::cout << "Parênteses de fechamento ')': " << closeParenthesesCount << std::endl;

    if (openParenthesesCount != closeParenthesesCount) {
        throw std::invalid_argument("Número de parênteses não correspondentes.");
    }

    if (!(stream >> firstOperand)) {
      throw std::invalid_argument("Formato inválido. Esperando um número.");
    }

    while (stream >> operatorSymbol) {
      if (operatorSymbol != '+' && operatorSymbol != '-') {
        throw std::invalid_argument(
            "Operador inválido. Apenas + e - são suportados.");
      }

      if (!(stream >> secondOperand)) {
        throw std::invalid_argument(
            "Formato inválido. Esperando um número após o operador.");
      }

      IExpression *rightOperand = new Number(secondOperand);

      if (operatorSymbol == '+') {
        result = new Addition(result, rightOperand);
      } else if (operatorSymbol == '-') {
        result = new Subtraction(result, rightOperand);
      }
    }

    return result;
  }
};

#endif // EXPRESSION_PARSER_H
