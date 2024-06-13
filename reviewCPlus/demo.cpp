#include <iostream>
#include <set>
using namespace std;

void func(int x)
{
    cout << x << endl;
}

void func1(void (*f)(int))
{
    f(1);
}

int main()
{
    func1(func);
    system("pause");
    return 0;
}