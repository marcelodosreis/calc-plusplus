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

class ExpressionParser
{
public:
  IExpression *parse(const std::string &input) const
  {
    std::unordered_set<char> validChars = {'(', ')', '+', '-', '*', '/'};
    std::vector<char> array;
    int parenthesisCount = 0;
    bool isLastOperator = false;
    std::vector<std::vector<int>> parenthesisBlocks;

    for (int i = 0; i < input.size(); i++)
    {
      char c = input[i];

      if (c == '+' || c == '-' || c == '*' || c == '/')
      {
        if (isLastOperator)
        {
          std::cout << "Error: Double operator issue: " << c << std::endl;
          return nullptr;
        }

        isLastOperator = true;
      }
      else
      {
        isLastOperator = false;
      }

      if (std::isdigit(c) || validChars.count(c))
      {
        if (c == ')')
        {
          parenthesisCount--;
          parenthesisBlocks.back().push_back(i);
        }

        if (c == '(')
        {
          parenthesisCount++;
          parenthesisBlocks.push_back({i});
        }
        array.push_back(c);
      }
    };

    if (parenthesisCount != 0)
    {
      std::cout << "Error: Unbalanced parentheses." << std::endl;
      return nullptr;
    }

    for (size_t i = 0; i < parenthesisBlocks.size(); ++i)
    {
      for (size_t j = 0; j < parenthesisBlocks[i].size() - 1; ++j)
      {
        int a = parenthesisBlocks[i][j];
        int b = parenthesisBlocks[i][j + 1];

        int start = std::min(a, b);
        int end = std::max(a, b);

        int quantity = end - start - 1;

        std::cout << "Quantity of numbers inside parenthesis: " << quantity << " ";
      }
      std::cout << std::endl;
    }

    IExpression *number1 = new Number(+3);
    IExpression *number2 = new Number(-2);
    IExpression *result = new Addition(number1, number2);
    return result;
  }
};
#endif // EXPRESSION_PARSER_H
