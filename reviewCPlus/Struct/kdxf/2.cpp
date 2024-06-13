#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = s.length();
    for (int i = 1; i < n; i++)
    {
        char ch = s[i];
        char lch = s[i - 1];
        int ck = ch - lch;
        if (ck > k)
        {
            k = -1;
            break;
        }
        else
        {
            k -= ck;
        }
    }
    cout << k << endl;
    system("pause");
    return 0;
}
