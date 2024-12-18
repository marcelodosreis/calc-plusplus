#ifndef IEXPRESSION_H
#define IEXPRESSION_H

class IExpression {
public:
    virtual double evaluate() const = 0;
    virtual ~IExpression() = default;
};

#endif // Domain - Interface::IExpression
