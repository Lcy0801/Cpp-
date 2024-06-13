#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int k;
    cin >> k;
    vector<int> goodFlag;
    goodFlag.resize(n - 1, 0);
    for (int i = 0; i < m; i++)
    {
        int start;
        cin >> start;
        int end;
        cin >> end;
        for (int i = start; i < end; i++)
        {
            goodFlag[i] = 1;
        }
    }
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        if (goodFlag[i])
        {
            res++;
        }
    }
    int maxRes = res;
    for (int i = 1; i <= n - k; i++)
    {
        if (goodFlag[i - 1])
        {
            res--;
        }
        if (goodFlag[i + k - 1])
        {
            res++;
        }
        maxRes = max(maxRes, res);
    }
    cout << maxRes << endl;
    return 0;
}