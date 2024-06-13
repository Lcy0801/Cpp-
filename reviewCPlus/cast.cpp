#include <iostream>
using namespace std;

int main()
{
    const string x = "Lcy";
    string &y = const_cast<string &>(x);
    y[0] = 'l';

    cout << x << endl;
    system("pause");
    return 0;
}