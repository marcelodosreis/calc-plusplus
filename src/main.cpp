#include <iostream>
#include "domain/entities/Number.cpp"
#include "domain/entities/Addition.cpp"

int main() {
    IExpression* num1 = new INumber(5.0);
    IExpression* num2 = new INumber(3.0);
    
    IExpression* sum = new IAddition(num1, num2);

    std::cout << "Valor da soma: " << sum->evaluate() << std::endl;

    delete sum;

    return 0;
}
// main.cpp