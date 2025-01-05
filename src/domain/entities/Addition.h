#ifndef ADDITION_H
#define ADDITION_H

#include "./IExpression.h"

class Addition : public IExpression {
public:
    Addition(IExpression* left, IExpression* right)
        : leftOperand(left), rightOperand(right) {}

    double evaluate() const override {
        return leftOperand->evaluate() + rightOperand->evaluate();
    }

private:
    IExpression* leftOperand;
    IExpression* rightOperand;
};

#endif // ADDITION_H
