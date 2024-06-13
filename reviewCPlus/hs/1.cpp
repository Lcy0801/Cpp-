#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
private:
    vector<vector<int>> allRes;
    vector<int> res;
    void backTracing(int k, int n, int start)
    {
        if (res.size() == k)
        {
            int sum = accumulate(res.begin(), res.end(), 0);
            if (sum == n)
            {
                allRes.push_back(res);
            }
            return;
        }
        for (int i = start; i <= 10 - k + res.size(); i++)
        {
            res.push_back(i);
            backTracing(k, n, i + 1);
            res.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backTracing(k, n, 1);
        return allRes;
    }
};