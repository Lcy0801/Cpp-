#include <iostream>
#include <vector>
using namespace std;

int SSM(vector<int>&vs)
{
    int n = vs.size();
    vector<int> res;
    res.reserve(n);
    if(n==0)
        return 0;
    if(n==1)
        return vs[0];
    if (n==2)
        return max(vs[0],vs[1]);
    if (n==3)
        return max(max(vs[0], vs[1]), vs[2]);
    res[0] = vs[0];
    res[1] = max(vs[0], vs[1]);
    res[2] = max(max(vs[0], vs[1]), vs[2]);
    bool flag = true;
    for (int i = 2; i < n;i++)
    {
        int r1 = res[i - 1];
        int r2 = res[i - 2] + vs[i];
        int r3 = r2;
        if(flag)
        {
            r3 = res[i - 1] + vs[i];
            flag = false;
        }
    }
    return res[n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> vs;
    for (int i = 0; i < n;i++)
    {
        int v;
        cin >> v;
        vs.push_back(v);
    }
    int res = SSM(vs);
    cout << res;
    system("pause");
    return 0;
}