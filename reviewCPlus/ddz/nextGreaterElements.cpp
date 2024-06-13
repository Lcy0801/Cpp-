#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    int maxV = nums[0];
    for (int i = 1; i < n; i++)
    {
        maxV = max(maxV, nums[i]);
    }
    vector<int> res;
    res.resize(n);
    set<int> resindexs;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == maxV)
        {
            res[i] = -1;
            resindexs.insert(i);
        }
    }
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i = (i + 1) % n)
    {
        int v = nums[i];
        if (v > nums[s.top()])
        {
            do
            {

                res[s.top()] = v;
                resindexs.insert(s.top());
                s.pop();
            } while (s.size() && v > nums[s.top()]);
        }
        s.push(i);
        if (resindexs.size() == n)
        {
            break;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 1};
    vector<int> res = nextGreaterElements(nums);
    for (auto v : res)
    {
        cout << v << endl;
    }
    system("pause");
    return 0;
}