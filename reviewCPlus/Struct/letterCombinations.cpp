#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    vector<string> allRes;
    string res;
    unordered_map<char, string> dict;

    void backTracing(string digits, int index)
    {
        if (res.length() == digits.length())
        {
            allRes.push_back(res);
            return;
        }
        for (int i = 0; i < dict[digits[index]].length(); i++)
        {
            res += dict[digits[index]][i];
            backTracing(digits, index + 1);
            res.erase(res.length() - 1, 1);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.length())
        {
            backTracing(digits, 0);
        }
        return allRes;
    }
    Solution()
    {
        dict.insert(make_pair('2', "abc"));
        dict.insert(make_pair('3', "def"));
        dict.insert(make_pair('4', "ghi"));
        dict.insert(make_pair('5', "jkl"));
        dict.insert(make_pair('6', "mno"));
        dict.insert(make_pair('7', "pqrs"));
        dict.insert(make_pair('8', "tuv"));
        dict.insert(make_pair('9', "wxyz"));
    }
};

int main()
{
    string digits = "23";
    // vector<string> res =  (Solution()).letterCombinations(digits);
    digits.erase(digits.length() - 1);
    digits.insert(digits.length(), 1, 'a');
    cout << digits << endl;
    system("pause");
    return 0;
}