#include <iostream>
#include <string>
using namespace std;
string replaceSpace(string s)
{
    for (int i = 0; i < s.size();i++)
    {
        char ch = s[i];
        if(ch == ' ')
        {
            s[i]='%';
            s = s.insert(i + 1, "20");
            i += 2;
        }
    }
    return s;
}

int main()
{
    string s = "123";
    string t = s;
    t[0] = '0';
    cout << s << endl;
    cout << t << endl;
    system("pause");
    return 0;
}