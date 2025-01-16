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
      for (size_t i = 0; i < input.length(); ++i) {
        std::cout << input[i] << std::endl;
    }

    IExpression *result = new Number(2);
    return result;
  }
};

#endif // EXPRESSION_PARSER_H
