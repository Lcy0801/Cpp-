#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool strCompare(string &str1, string &str2)
{
    if (str1.length() != str2.length())
        return false;
    vector<char> chs1;
    vector<char> chs2;
    for (auto ch : str1)
    {
        chs1.push_back(ch);
    }
    for (auto ch : str2)
    {
        chs2.push_back(ch);
    }
    sort(chs1.begin(), chs1.end());
    sort(chs2.begin(), chs2.end());
    for (int i = 0; i < chs1.size(); i++)
    {
        if (chs1[i] != chs2[i])
            return false;
    }
    return true;
}

vector<int> solution(string &str1, string &str2)
{
    vector<int> res;
    int l1 = str1.length();
    int l2 = str2.length();
    if (l1 < l2)
        return res;
    for (int i = 0; i <= l1-l2; i++)
    {
        string subStr = str1.substr(i, l2);
        if(strCompare(subStr,str2))
        {
            res.push_back(i);
        }
    }
    return res;
}

int main()
{
    string str1 = "abababc";
    string str2 = "ab";
    vector<int> res = solution(str1, str2);
    for(auto v:res)
    {
        cout << v << endl;
    }
    system("pause");
    return 0;
}