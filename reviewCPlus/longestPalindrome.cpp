#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

bool isPalindrome(const string &s, int start, int end)
{
    if (start == end)
        return true;
    int i = start;
    int j = end;
    while (j - i >= 1)
    {
        char head = s[i];
        char tail = s[j];
        if (head != tail)
            return false;
        i++;
        j--;
    }
    return true;
}

string longestPalindrome(string s)
{
    int l = s.length();
    if (l == 0)
        return "";
    pair<int, int> res = make_pair(0, 0);
    map<char, vector<int>> chMap;
    map<char, vector<int>>::iterator it;
    for (int i = 0; i < l; i++)
    {
        char ch = s[i];
        if (chMap.count(ch))
        {
            vector<int> chLoca = chMap[ch];
            for (int j = 0; j < chLoca.size(); j++)
            {
                bool flag = isPalindrome(s,chLoca[j],i);
                if (flag)
                {
                    res = i-chLoca[j] > res.second-res.first ? make_pair(chLoca[j],i) : res;
                    break;
                }
            }
            chMap[ch].push_back(i);
        }
        else
        {
            chMap.insert(make_pair(ch, vector<int>(1, i)));
        }
    }
    return s.substr(res.first, res.second - res.first + 1);
}

int main()
{
    string s = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa";
    string Palindrome = longestPalindrome(s);
    cout << Palindrome << endl;
    system("pause");
    return 0;
}