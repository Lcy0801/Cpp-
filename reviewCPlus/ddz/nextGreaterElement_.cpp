#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n,-1);
    res.reserve(n);
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n * 2; i++)
    {
        int j = i % n;
        if (nums[j] > nums[s.top()])
        {
            do
            {
                res[s.top()] = nums[j];
                s.pop();
            } while (s.size() && nums[j] > nums[s.top()]);
        }
        s.push(j);
    }
    return res;
}