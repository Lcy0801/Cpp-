#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >>n;
    int k;
    cin >> k;
    int sum = 0;
    for (int i = 1; i <= n;i++)
    {
        sum += i * k;
    }
    return sum;
}