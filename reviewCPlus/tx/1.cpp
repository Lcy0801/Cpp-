#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int k = g.size() - 1;
            for (int j = 0; j < g.size(); j++)
            {
                if (g[j] <= s[i])
                    continue;
                k = j - 1;
                break;
            }

            while (k >= 0)
            {
                if (g[k])
                {
                    g[k] = 0;
                    res++;
                    break;
                }
                k--;
            }
        }
        return res;
    }
};