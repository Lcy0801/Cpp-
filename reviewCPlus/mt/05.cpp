#include <iostream>
#include <vector>
using namespace std;

int SSS(const vector<int> &vs, int s)
{
    int n = vs.size();
    int state[n][s + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            state[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
        state[i][0] = 0;
    for (int j = 0; j <= s; j++)
    {
        if (j >= vs[0])
        {
            state[0][j] = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (vs[i] > j)
            {
                state[i][j] = state[i - 1][j];
            }
            else
            {
                state[i][j] = max(state[i - 1][j], state[i - 1][j - vs[i]] + 1);
            }
        }
    }
    return state[n - 1][s];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int v_;
        cin >> v_;
        v.push_back(v_ * v_);
    }
    vector<int> res;
    for (int i = 0; i < m; i++)
    {
        int s;
        cin >> s;
        int res_ = SSS(v, s);
        res.push_back(res_);
    }
    for (int i = 0; i < m; i++)
    {
        cout << res[i] << "\t";
    }
    system("pause");
    return 0;
}