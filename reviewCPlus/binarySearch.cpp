#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

template <typename T>
bool binarySearch(vector<T> v, T e)
{
      
}

int main()
{
    srand((unsigned int)time(NULL));
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(rand() % 100);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}