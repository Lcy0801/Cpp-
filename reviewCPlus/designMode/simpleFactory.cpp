#include <iostream>
using namespace std;

class Operator
{
public:
    int leftValue;
    int rightValue;
    virtual int getResult() = 0;
    Operator(int lv, int rv)
    {
        leftValue = lv;
        rightValue = rv;
    }
};

class Add : public Operator
{
public:
    Add(int lv, int rv) : Operator(lv, rv){};
    int getResult()
    {
        return leftValue + rightValue;
    }
};
class Sub : public Operator
{
public:
    Sub(int lv, int rv) : Operator(lv, rv){};
    int getResult()
    {
        return leftValue - rightValue;
    }
};
class Multiply : public Operator
{
public:
    Multiply(int lv, int rv) : Operator(lv, rv){};
    int getResult()
    {
        return leftValue * rightValue;
    }
};
class Divide : public Operator
{
public:
    Divide(int lv, int rv) : Operator(lv, rv){};
    int getResult()
    {
        return leftValue / rightValue;
    }
};

class OperatorFactory
{
public:
    static Operator *createOperation(char c, int lv, int rv)
    {
        Operator *operation = nullptr;
        switch (c)
        {
        case '+':
            operation = new Add(lv, rv);
            break;
        case '-':
            operation = new Sub(lv, rv);
            break;
        case '*':
            operation = new Multiply(lv, rv);
            break;
        case '/':
            operation = new Divide(lv, rv);
            break;
        default:
            break;
        }
        return operation;
    }
};

int main()
{
    Operator *add = OperatorFactory::createOperation('+',1,2);
    Operator *sub = OperatorFactory::createOperation('-',1,2);
    Operator *mul = OperatorFactory::createOperation('*',1,2);
    Operator *div = OperatorFactory::createOperation('/',1,2);
    cout << add->getResult() << endl;
    cout << sub->getResult() << endl;
    cout << mul->getResult() << endl;
    cout << div->getResult() << endl;
    system("pause");
    return 0;
}