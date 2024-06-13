#include <iostream>
#include <vector>
using namespace std;

vector<int> twoDifferentNumber(const vector<int> &numbers)
{
    int res = 0;
    for (auto v : numbers)
    {
        res = res ^ v;
    }
    int tmp = 1;
    while (!res & tmp)
    {
        tmp *= 2;
    }
    int num1 = 0;
    int num2 = 0;
    for (auto v : numbers)
    {
        if (v & tmp)
        {
            num1 = num1 ^ v;
        }
        else
        {
            num2 = num2 ^ v;
        }
    }
    vector<int> vs = {num1, num2};
    return vs;
}

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 7};
    vector<int> res = twoDifferentNumber(numbers);
    for(auto v:res)
    {
        cout << v << endl;
    }
    system("pause");
    return 0;
}