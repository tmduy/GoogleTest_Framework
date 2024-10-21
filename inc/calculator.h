#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
public:
    virtual int add(int a, int b);
    virtual int subtract(int a, int b);
    virtual int multiply(int a, int b);
    virtual int divide(int a, int b);
    virtual int complex_operator(int a, int b);
    virtual int MyFunc(Calculator& calc, int a, int b);
};

#endif // CALCULATOR_H
