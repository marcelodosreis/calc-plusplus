#include "../interfaces/ISubtraction.h"

inline ISubtraction::ISubtraction(IExpression* left, IExpression* right)
    : left(left), right(right) {}

inline double ISubtraction::evaluate() const {
    return left->evaluate() - right->evaluate();
}

// Domain - Entities::Addition