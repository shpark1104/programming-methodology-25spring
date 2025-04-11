#include "calculator.h"
#include <stdexcept>

int Calculator::add(int a, int b) {
    // TODO
    if(a + b != (long long int)a + (long long int)b) throw std::overflow_error("overflow error in add");
    return a + b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if(a - b != (long long int)a - (long long int)b) throw std::overflow_error("overflow error in sub");
    return a - b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if(a * b != (long long int)a * (long long int)b) throw std::overflow_error("overflow error in mul");
    return a * b;
}

int Calculator::div(int a, int b) {
    // TODO
    //division by zero
    if(b == 0) throw std::invalid_argument("division by zero");
    //only case of raising "Floating point exception" while integer division
    if(a == int(1) << 31 && b == -1) throw std::overflow_error("overflow error in div");
    if(a / b != (long long int)a / (long long int)b) throw std::overflow_error("overflow error in div");
    return a / b;
}