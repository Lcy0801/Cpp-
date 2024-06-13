#include <iostream>
#include <string>
#include <stack>
using namespace std;

string solution(const string &str)
{
    stack<char> s;
    string res = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch != ']')
        {
            s.push(ch);
            continue;
        }
        while (true)
        {
            char top = s.top();
            if (top != '[')
            {
                res = top + res;
                s.pop();
                continue;
            }
            else
            {
                s.pop();
                break;
            }
        }
        int num = s.top() - '0';
        s.pop();
        string tmp = "";
        for (int j = 0; j < num; j++)
        {
            tmp += res;
        }
        res = tmp;
    }
    return res;
}

int main()
{
    string str = "3[a1[ab2[a]]]";
    string res = solution(str);
    cout << res << endl;
    system("pause");
    return 0;
}