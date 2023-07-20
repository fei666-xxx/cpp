#include<iostream>

class Calculator
{
public:
    virtual int GetResult()=0;

    int num1,num2;
};

class AddCalculator: public Calculator
{
public:
    AddCalculator() {}

    AddCalculator(int _num1, int _num2)
    {
        num1 = _num1;
        num2 = _num2;
    }

    int GetResult()
    {
        return num1+num2;
    }
};

class SubCalculator: public Calculator
{
public:
    SubCalculator() {}

    SubCalculator(int _num1, int _num2)
    {
        num1 = _num1;
        num2 = _num2;
    }

    int GetResult()
    {
        return num1-num2;
    }
};

class MulCalculator: public Calculator
{
public:
    MulCalculator() {}

    MulCalculator(int _num1, int _num2)
    {
        num1 = _num1;
        num2 = _num2;
    }

    int GetResult()
    {
        return num1*num2;
    }
};

class DivCalculator: public Calculator
{
public:
    DivCalculator() {}

    DivCalculator(int _num1, int _num2)
    {
        num1 = _num1;
        num2 = _num2;
    }

    int GetResult()
    {
        return num1/num2;
    }
};

int main()
{
    Calculator* cal = new AddCalculator(100,20);
    std::cout << cal->GetResult() << std::endl;
    delete cal;

    cal = new SubCalculator(100,20);
    std::cout << cal->GetResult() << std::endl;
    delete cal;

    cal = new MulCalculator(100,20);
    std::cout << cal->GetResult() << std::endl;
    delete cal;

    cal = new DivCalculator(100,20);
    std::cout << cal->GetResult() << std::endl;
    delete cal;

    return 0;
}