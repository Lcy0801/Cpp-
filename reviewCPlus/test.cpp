#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    double x=1;
    double &y = x;
    int a = 1;
    int *z = &a;
    cout << sizeof(y) << endl;
    cout << sizeof(z) << endl;
    system("pause");
    return 0;
}