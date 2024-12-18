#ifndef INUMBER_H
#define INUMBER_H

#include "IExpression.h"

class INumber : public IExpression {
public:
    INumber(double value);
    double evaluate() const override;

private:
    double value;

};

#endif // Domain - Interface::INumber