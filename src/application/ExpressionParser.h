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
      std::cout << "Parenteses Estão faltando" << std::endl;
    }

    std::string str(array.begin(), array.end());

    IExpression *result = new Number(2);
    return result;
  }
};

#endif // EXPRESSION_PARSER_H
