#include "../interfaces/IAddition.h"

inline IAddition::IAddition(IExpression* left, IExpression* right)
    : left(left), right(right) {}

inline double IAddition::evaluate() const {
    return left->evaluate() + right->evaluate();
}

// Domain - Entities::Addition