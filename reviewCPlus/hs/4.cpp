#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<vector<int>> allRes;
    vector<int> res;
    void backTracing(vector<int> &nums, int target, int index)
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
            if (i > index && nums[i] == nums[i - 1])
                continue;
            res.push_back(nums[i]);
            backTracing(nums, target, i + 1);
            res.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backTracing(candidates, target, 0);
        return allRes;
    }
};
