#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allRes;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int v1 = nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int v2 = nums[left];
                int v3 = nums[right];
                int sum = v1 + v2 + v3;
                if (sum == 0)
                {
                    vector<int> res;
                    res.push_back(v1);
                    res.push_back(v2);
                    res.push_back(v3);
                    allRes.push_back(res);
                    left++;
                    right--;
                    while (left < right && (nums[left - 1] == nums[left]))
                    {
                        left++;
                    }
                    while (left < right && (nums[right + 1] == nums[right]))
                    {
                        right--;
                    }
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return allRes;
    }
};