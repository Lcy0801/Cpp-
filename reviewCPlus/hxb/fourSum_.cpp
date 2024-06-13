#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end(), less<int>());
    for (int i = 0; i < n - 3; i++)
    {
        long a = nums[i];
        if ((a > target && a >= 0) || (i > 0 && a == nums[i - 1]))
        {
            continue;
        }
        for (int j = i + 1; j < n - 2; j++)
        {
            long b = nums[j];
            if ((a + b > target && b >= 0) || (j > i + 1 && b == nums[j - 1]))
            {
                continue;
            }
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                long c = nums[left];
                long d = nums[right];
                long sum = a + b + c + d;
                if (sum == target && (left == j + 1 || nums[left] != nums[left - 1]))
                {
                    vector<int> resi;
                    resi.push_back(a);
                    resi.push_back(b);
                    resi.push_back(c);
                    resi.push_back(d);
                    res.push_back(resi);
                    left++;
                    right--;
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
    return res;
}
