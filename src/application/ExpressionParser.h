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
    bool isLastOperator = true;

    for (char c : input) {
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

    for (size_t i = 0; i < input.size(); ++i) {
      char current = input[i];

      if (isdigit(current) || current == '.') {
        isLastOperator = false;
      } else if (current == '+' || current == '-' || current == '*' || current == '/') {

        if (isLastOperator && (current == '+' || current == '-')) {
          std::cout << "Erro: Operadores unários consecutivos inválidos na posição " << i << "." << std::endl;
          return nullptr;
        }

        if (current == '+' || current == '-') {
          if (i == 0 || input[i - 1] == '(' || input[i - 1] == '*' || input[i - 1] == '/' || input[i - 1] == '+' || input[i - 1] == '-') {
            isLastOperator = false;
          } else {
            isLastOperator = true;
          }
        } else {
          isLastOperator = true;
        }
      } else if (current == ' ') {
        continue;
      }
    }

    std::string str(array.begin(), array.end());

    IExpression *result = new Number(2);
    return result;
  }
};
#endif // EXPRESSION_PARSER_H
