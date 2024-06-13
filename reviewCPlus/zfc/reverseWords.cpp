#include <string>
#include <iostream>
using namespace std;
string reverseWords(string s)
{
    string res;
    int left = -1, right = -1;
    int l = s.size();
    for (int i = l - 1; i >= 0; i--)
    {
        if (right == -1 && s[i] != ' ')
        {
            right = i;
        }
        else if (right != -1 && (s[i] == ' '))
        {
            left = i;
            string word = s.substr(left + 1, right - left);
            res = res.size() == 0 ? word : res + ' ' + word;
            right = -1;
        }
    }
    if (right != -1)
    {
        res = res.size() == 0 ? s : res + ' ' + s.substr(0, right + 1);
    }
    return res;
    s.erase();
}