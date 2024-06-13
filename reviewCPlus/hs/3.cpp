#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
private:
    vector<vector<int>> allRes;
    vector<int> res;
    void backTracing(vector<int> nums, int target, int index)
    {
        int sum = accumulate(res.begin(), res.end(), 0);
        if (sum >= target)
        {
            if (sum == target)
            {
                allRes.push_back(res);
            }
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            if (nums[i] > (target - sum))
                continue;
            res.push_back(nums[i]);
            backTracing(nums, target, i);
            res.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backTracing(candidates, target, 0);
        return allRes;
    }
};