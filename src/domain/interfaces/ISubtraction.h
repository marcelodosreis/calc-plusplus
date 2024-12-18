#ifndef ISUBTRACTION_H
#define ISUBTRACTION_H

#include "IExpression.h"

class ISubtraction : public IExpression {
public:
    ISubtraction(IExpression* left, IExpression* right);
    double evaluate() const override;

private:
    IExpression* left;
    IExpression* right;

};

#endif // Domain - Interface::ISubtraction