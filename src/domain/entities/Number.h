#ifndef NUMBER_H
#define NUMBER_H

#include "./IExpression.h"

class Number : public IExpression {
public:
    explicit Number(double value)
        : value(value) {}

    double evaluate() const {
        return value;
    }

private:
    double value;
};

#endif // NUMBER_H
