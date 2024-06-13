#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    int l = s.length();
    if (l == 1)
        return true;
    int left = 0;
    int right = l - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

class Solution
{
private:
    vector<vector<string>> allRes;
    vector<int> res;
    void backTracing(string s)
    {
        if (res.size() == s.length() - 1)
        {
            vector<string> resStr;
            int start = 0;
            bool flag = true;
            for (int i = 0; i < res.size(); i++)
            {
                if (!res[i])
                    continue;
                int end = i + 1;
                string pStr = s.substr(start, end - start);
                if (isPalindrome(pStr))
                {
                    resStr.push_back(pStr);
                    start = end;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag && isPalindrome(s.substr(start)))
            {
                resStr.push_back(s.substr(start));
                allRes.push_back(resStr);
            }
            return;
        }
        res.push_back(0);
        backTracing(s);
        res.pop_back();
        res.push_back(1);
        backTracing(s);
        res.pop_back();
    }

public:
    vector<vector<string>> partition(string s)
    {
        backTracing(s);
        return allRes;
    }
};