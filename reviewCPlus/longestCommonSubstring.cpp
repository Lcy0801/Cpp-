#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestCommonSubstring(string &a, string &b)
    {
        int res = 0;
        vector<vector<int>> dp(a.length(), vector<int>(b.length(), 0));
        for (int i = 0; i < a.length(); i++)
        {
            for (int j = 0; j < b.length(); j++)
            {
                if (a[i] == b[j])
                {
                    if (i && j)
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = 1;
                    }
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};

int main()
{
}