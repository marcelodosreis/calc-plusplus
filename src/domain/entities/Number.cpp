#include "../interfaces/INumber.h"

inline INumber::INumber(double value) : value(value) {}

inline double INumber::evaluate() const {
    return value;
}

// Domain - Entities::Number