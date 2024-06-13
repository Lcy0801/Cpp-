#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap(vector<int> &heights)
{
    int n = heights.size();
    stack<int> s;
    s.push(0);
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (heights[i] > heights[s.top()])
        {
            do
            {
                int j = s.top();
                s.pop();
                if(s.size())
                {
                    int k = s.top();
                    res += (i - k - 1) * (min(heights[i], heights[k]) - heights[j]);
                }
            } while (s.size() && heights[i] > heights[s.top()]);
        }
        s.push(i);
    }
    return res;
}
