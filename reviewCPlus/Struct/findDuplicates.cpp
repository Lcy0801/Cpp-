#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i])] < 0)
            {
                res.push_back(abs(nums[i]));
            }
            else
            {
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }
        }
        return res;
    }
};
