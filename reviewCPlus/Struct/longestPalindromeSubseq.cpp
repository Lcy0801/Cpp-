#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string s;
    int longestPalindromeSubseq(string s)
    {
        this->s = s;
        return longestPalindromeSubseqByIndex(0, s.length() - 1);
    }
    int longestPalindromeSubseqByIndex(int start, int end)
    {
        if (start == end)
        {
            return 1;
        }
        if (start > end)
        {
            return 0;
        }
        int n = end - start + 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            char chi = s[i + start];
            int index = -1;
            for (int j = 0; j < i; j++)
            {
                char chj = s[j + start];
                if (chj == chi)
                {
                    index = j;
                    break;
                }
            }
            if (index == -1)
            {
                dp[i] = dp[i - 1];
            }
            else
            {
                dp[i] = max(dp[i - 1], longestPalindromeSubseqByIndex(start + index + 1, start + i - 1) + 2);
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    string s = "euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew";
    int res = Solution().longestPalindromeSubseq(s);
    cout << res << endl;
    system("pause");
    return 0;
}