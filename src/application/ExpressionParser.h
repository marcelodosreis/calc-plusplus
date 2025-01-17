#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include "../domain/entities/Addition.h"
#include "../domain/entities/Number.h"
#include "../domain/entities/Subtraction.h"
#include <cctype> // Para std::isdigit
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_set>

class ExpressionParser {
public:
  IExpression *parse(const std::string &input) const {

    std::unordered_set<char> validChars = {'(', ')', '+', '-', '*', '/'};

    for (char c : input) {
      if (std::isdigit(c) || validChars.count(c)) {
        std::cout << c << ": Caractere Valido" << std::endl;
      } else {
        std::cout << c << ": Caractere Invalido" << std::endl;
      }
    }

    IExpression *result = new Number(2);
    return result;
  }
};

#endif // EXPRESSION_PARSER_H
