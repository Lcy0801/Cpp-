#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < strs.size(); i++)
        {
            int n_zero;
            int n_one;
            zero_one_num(strs[i], n_zero, n_one);
            for (int j = m; j >= n_zero; j--)
            {
                for (int k = n; k >= n_one; k--)
                {
                    dp[j][k] = max(dp[j - n_zero][k - n_one] + 1, dp[j][k]);
                }
            }
        }
        return dp[m][n];
    }

    void zero_one_num(string &str, int &n_zero, int &n_one)
    {
        int l = str.length();
        n_zero = 0;
        n_one = 0;
        for (int i = 0; i < l; i++)
        {
            char ch = str[i];
            if (ch == '0')
            {
                n_zero++;
            }
            else
            {
                n_one++;
            }
        }
        return;
    }
};