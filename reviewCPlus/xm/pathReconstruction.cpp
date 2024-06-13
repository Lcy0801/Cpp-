#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
using namespace std;

char solution(const string &pathTree, char fd1, char fd2)
{
    stack<char> s;
    unordered_map<char, char> dicts;
    for (int i = 0; i < pathTree.length(); i++)
    {
        char ch = pathTree[i];
        if (ch == ',' || ch == ' ')
            continue;
        if (ch != ')')
        {
            s.push(ch);
            continue;
        }
        vector<char> tops;
        while (true)
        {
            char top = s.top();
            if (top != '(')
            {
                tops.push_back(top);
                s.pop();
            }
            else
            {
                s.pop();
                break;
            }
        }
        for (auto ch : tops)
        {
            dicts.insert(make_pair(ch, s.top()));
        }
    }
    // 还原完整路径
    string path1 = "";
    path1.push_back(fd1);
    while (true)
    {
        auto it = dicts.find(fd1);
        if (it != dicts.end())
        {
            path1.push_back(it->second);
            fd1 = it->second;
            continue;
        }
        break;
    }
    string path2 = "";
    path2.push_back(fd2);
    while (true)
    {
        auto it = dicts.find(fd2);
        if (it != dicts.end())
        {
            path2.push_back(it->second);
            fd2 = it->second;
            continue;
        }
        break;
    }
    char res;
    cout << path1 << "\t" << path2 << endl;
    bool flag = false;
    for (int i = path1.length() - 1, j = path2.length() - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (path1[i] == path2[j])
            continue;
        flag = true;
        res = path1[i + 1];
        break;
    }
    if(!flag)
    {
        res = path1.length() < path2.length() ? path1[0] : path2[0];
    }
    return res;
}

int main()
{
    string pathTree = "a (b(e,f(g,h)), c, d(i,j))";
    char res = solution(pathTree, 'd', 'g');
    cout << res << endl;
    system("pause");
    return 0;
}