#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string &zz, string &lx, string &fz)
{
    int n = zz.length();
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (lx[i] == '1')
        {
            zz[i] = '0';
        }
        else if (zz[i] == '1')
        {
            num++;
        }
        else if (fz[i] == '1')
        {
            zz[i] = '1';
            num++;
        }
    }
    return num;
}

int main()
{
    int n;
    cin >> n;
    string zz;
    cin >> zz;
    int m;
    cin >> m;
    vector<string> lxs;
    vector<string> fzs;
    for (int i = 0; i < m; i++)
    {
        string lx;
        cin >> lx;
        string fz;
        cin >> fz;
        lxs.push_back(lx);
        fzs.push_back(fz);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        int res = solution(zz, lxs[k - 1], fzs[k - 1]);
        cout << res << endl;
    }
    return 0;
}