#include <iostream>
#include <string>
using namespace std;

int solution(string &s, int n)
{
    if (n == 1)
        return 1;
    int res = 1;
    int val = 1;
    char ch = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] == ch)
        {
            val++;
            res += val;
        }
        else
        {
            int j;
            for (j = i + 1; j < n; j++)
            {
                if (s[j] != s[i])
                    break;
            }
            int valSum = (j - i + 1) / 2 * (j - i);
            if (val < valSum || j == n)
            {
                val = 1;
                ch = s[i];
                res += val;
            }
            else
            {
                i = j - 1;
            }
        }
    }
    return res;
}

int main()
{
    int n;
    // cin >> n;
    string s;
    // cin >> s;
    s = "111111111111100";
    n = 20;
    int res = solution(s, s.length());
    cout << res << endl;
    system("pause");
    return 0;
}