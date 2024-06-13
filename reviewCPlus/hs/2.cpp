#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    vector<string> allRes;
    string res;
    unordered_map<char, string> dict;
    void backTracing(string str, int index)
    {
        if (res.length() == str.length())
        {
            allRes.push_back(res);
            return;
        }
        for (auto ch : dict[str[index]])
        {
            res.push_back(ch);
            backTracing(str, index + 1);
            res.pop_back();
        }
    }

public:
    Solution()
    {
        dict.insert(make_pair('2', "abc"));
        dict.insert(make_pair('3', "def"));
        dict.insert(make_pair('4', "ghi"));
        dict.insert(make_pair('5', "jkl"));
        dict.insert(make_pair('6', "mno"));
        dict.insert(make_pair('7', "pqrs"));
        dict.insert(make_pair('8', "tuv"));
        dict.insert(make_pair('9', "wxzy"));
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.length())
        {
            backTracing(digits, 0);
        }
        return allRes;
    }
};