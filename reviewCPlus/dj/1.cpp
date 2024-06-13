#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int solution(string &s)
{
    unordered_map<char, vector<int>> dict;
    int L = s.length();
    int res = L;
    for (int i = 0; i < L; i++)
    {
        char ch = s[i];
        unordered_map<char, vector<int>>::iterator it = dict.find(ch);
        if (it != dict.end())
        {
            vector<int> indices = it->second;
            for (auto start : indices)
            {
                int end = i;
                while (s[start] == s[end])
                {
                    start++;
                    end--;
                    if (start > end)
                    {
                        res++;
                        break;
                    }
                }
            }
            it->second.push_back(i);
        }
        else
        {
            dict.insert(make_pair(ch,vector<int>(1,i)));
        }
    }
    return res;
}

int main()
{
    string s;
    s = "aaa";
    int res = solution(s);
    cout << res << endl;
    system("pause");
    return 0;
}