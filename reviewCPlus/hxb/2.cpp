#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int add_(int a, int b, int (*fun)(int, int))
{
    return fun(a, b);
}

int *subtract(int a, int b)
{
    int *c = new int(a - b);
    return c;
}
int main()
{
    int *res = subtract(2, 1);
    cout << *res << endl;

    // int (*fun)(int, int);
    // fun = &add;
    // cout << add_(1, 2, fun);
    // int s1[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     s1[i] = i;
    // }
    // int *s2[10];
    // int(*s3)[10] = &s1;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << (*s3)[i] << endl;
    // }
    system("pause");
    return 0;
}