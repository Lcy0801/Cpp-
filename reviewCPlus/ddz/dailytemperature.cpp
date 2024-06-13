#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> res;
    int n = temperatures.size();
    res.resize(n);
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        if (temperatures[i] >  temperatures[s.top()])
        {
            do
            {
                res[s.top()] = i - s.top();
                s.pop();
            } while (s.size() && temperatures[s.top()]<temperatures[i]);

        }
        s.push(i);
    }
    while (s.size())
    {
        res[s.top()]=0;
        s.pop();
    }
    return res;
}