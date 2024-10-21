#include "../inc/calculator.h"
#include <stdexcept>

int Calculator::add(int a, int b)
{
    return a + b;
}

int Calculator::subtract(int a, int b)
{
    return a - b;
}

int Calculator::multiply(int a, int b)
{
    return a * b;
}

int Calculator::divide(int a, int b)
{
    if (b == 0)
	  {
        throw std::invalid_argument("Division by zero");
    }

    return a / b;
}

int Calculator::complex_operator(int a, int b)
{
    int var_1 = this->add(a, b);
    int var_2 = this->subtract(a, b);
    
    int retVal = this->multiply(var_1, var_2);
    
    return retVal;
}

int Calculator::MyFunc(Calculator& calc, int a, int b)
{
    int result1 = calc.complex_operator(a, b);
    int result2 = calc.complex_operator(b, a);
    
    if (result1 > result2) 
    {
        return calc.add(result1, result2);
    } 
    else 
    {
        return calc.multiply(result1, result2);
    }
}
