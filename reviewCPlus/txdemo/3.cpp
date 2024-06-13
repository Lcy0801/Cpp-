#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    stringstream ss(s);
    vector<int> nums;
    string num;
    while (getline(ss, num, ' '))
    {
        nums.push_back(atoi(num.c_str()));
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (j - i == 1)
            {
                dp[i][j] = 1;
                res++;
            }
            else
            {
                if (dp[i][j - 1] && nums[j - 1] >= nums[i] && nums[j] <= nums[j - 1])
                {
                    dp[i][j] = 1;
                    res++;
                }
            }
        }
    }
}