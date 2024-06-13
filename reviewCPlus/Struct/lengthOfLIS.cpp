#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Print
{
public:
    void operator()(int v)
    {
        cout << v << "\t";
    }
};

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector<int>> seq(nums.size(), vector<int>());
        seq[0] = vector<int>(1, nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            seq[i] = seq[i - 1];
            cout << endl;
            if (nums[i] > seq[i - 1][seq[i - 1].size() - 1])
            {
                seq[i].push_back(nums[i]);
            }
            else if (seq[i - 1].size() == 1 || nums[i] > seq[i - 1][seq[i - 1].size() - 2])
            {
                seq[i][seq[i].size() - 1] = nums[i];
            }
            for_each(seq[i].begin(), seq[i].end(), Print());
        }
        return seq[nums.size() - 1].size();
    }
};

int main()
{
    int array[] = {3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    int res = Solution().lengthOfLIS(nums);
    cout << res << endl;
    system("pause");
    return 0;
}