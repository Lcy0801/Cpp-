#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int SSM(const vector<int> &vs, int start, int end)
{
    int n = end - start + 1;
    if (n == 1)
        return vs[start];
    if (n == 2)
        return max(vs[start], vs[end]);
    vector<int> state;
    state.resize(n);
    state[0] = vs[start];
    state[1] = max(vs[start], vs[start + 1]);
    for (int i = 2; i < n; i++)
    {
        state[i] = max(state[i - 1], state[i - 2] + vs[start + i]);
    }
    return state[n - 1];
}

int main()
{
    // 糖果个数
    int n;
    cin >> n;
    vector<int> vs;
    vs.reserve(n);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n;i++)
    {
        int v = rand() % 10;
        cout << v << "\t";
        vs.push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        vs.push_back(i);
    }
    int res = vs[0];
    for (int k = 1; k < n; k++)
    {
        int index_before = k - 3;
        int maxl = 0;
        if (index_before >= 0)
            maxl = SSM(vs, 0, index_before);
        int index_after = k + 2;
        int maxr;
        maxr = 0;
        if (index_after <= n - 1)
            maxr = SSM(vs, index_after, n - 1);
        int maxk = maxl + vs[k - 1] + vs[k] + maxr;
        res = max(res, maxk);
    }
    cout << res << endl;
    system("pause");
    return 0;
}