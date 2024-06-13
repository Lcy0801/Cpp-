#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), 0));
        int res = 0;
        for (int i = 0; i < text1.length(); i++)
        {
            for (int j = 0; j < text2.length(); j++)
            {
                if (text1[i] == text2[j])
                {
                    if (i && j)
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else
                    {
                        dp[i][j] = 1;
                    }
                }
                else
                {
                    if (i && j)
                    {
                        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                    }
                    else if (i)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else if (j)
                    {
                        dp[i][j] = dp[i][j - 1];
                    }
                    
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main()
{
    int x = max(1,2);
    cout<<x<<endl;
    system("pause");
    return 0;
}