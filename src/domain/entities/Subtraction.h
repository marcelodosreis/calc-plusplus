#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "./IExpression.h"

class Subtraction : public IExpression {
public:
    Subtraction(IExpression* left, IExpression* right)
        : leftOperand(left), rightOperand(right) {}

    double evaluate() const override {
        return leftOperand->evaluate() - rightOperand->evaluate();
    }

private:
    IExpression* leftOperand;
    IExpression* rightOperand;
};

#endif // SUBTRACTION_H
