#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include "../domain/entities/Addition.h"
#include "../domain/entities/Number.h"
#include "../domain/entities/Subtraction.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

class ExpressionParser {
public:
  IExpression *parse(const std::string &input) const {
    std::unordered_set<char> validChars = {'(', ')', '+', '-', '*', '/'};
    std::vector<char> array;
    int parenthesisCount = 0;
    bool isLastOperator = false;

    for (char c : input) {

      if (c == '+' || c == '-' || c == '*' || c == '/') {
        if (isLastOperator) {
          std::cout << "Erro: Problema de Duplo Sinal: " << c << std::endl;
          return nullptr;
        }

        isLastOperator = true;
      } else {
        isLastOperator = false;
      }

      if (c == ')') {
        parenthesisCount--;
      }

      if (std::isdigit(c) || validChars.count(c)) {
        if (c == '(') {
          parenthesisCount++;
        }
        array.push_back(c);
      }
    }

    if (parenthesisCount != 0) {
      std::cout << "Erro: Parênteses desbalanceados." << std::endl;
      return nullptr;
    }

    IExpression *result = new Number(2);
    return result;
  }
};
#endif // EXPRESSION_PARSER_H
