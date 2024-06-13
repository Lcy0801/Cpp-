#include <iostream>
#include <vector>
using namespace std;

// 前缀和解法会超时
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         vector<int> sums;
//         sums.reserve(nums.size());
//         int sum = 0;
//         for (auto v : nums)
//         {
//             sum += v;
//             sums.push_back(sum);
//         }
//         int res = INT_MIN;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int si = sums[i];
//             for (int j = i; j < nums.size(); j++)
//             {
//                 int sj = sums[j];
//                 res = max(sj - si + nums[i], res);
//             }
//         }
//         return res;
//     }
// };

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int l = nums.size();
        if (l == 1)
            return nums[0];
        vector<int> dp(nums.begin(), nums.end());
        int res = dp[0];
        for (int i = 1; i < l; i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};