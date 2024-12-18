#ifndef IADDITION_H
#define IADDITION_H

#include "IExpression.h"

class IAddition : public IExpression {
public:
    IAddition(IExpression* left, IExpression* right);
    double evaluate() const override;

private:
    IExpression* left;
    IExpression* right;

};

#endif // Domain - Interface::IAddition