#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

class Print
{
public:
    void operator()(int v)
    {
        cout << v << "\t";
    }
};

int main()
{
    int s[10];
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < 10; i++)
    {
        s[i] = rand() % 10;
    }
    for_each(s, s + 10, Print());
    cout << endl;
    sort(s, s + 10, less<int>());
    for_each(s, s + 10, Print());
    cout << endl;
    system("pause");
    return 0;
}