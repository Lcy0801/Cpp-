#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
using namespace std;

int solution(stack<pair<int, int>> tracks)
{
    int ldrow = 0;
    int ldcol = 0;
    int res = 0;
    pair<int, int> last = tracks.top();
    tracks.pop();
    while (tracks.size())
    {
        pair<int, int> top = tracks.top();
        int drow = top.first - last.first;
        int dcol = top.second - last.second;
        if (dcol != ldcol || drow != ldcol)
        {
            res++;
        }
        ldcol = dcol;
        ldrow = drow;
        last = top;
        tracks.pop();
    }
    return res;
}

int main()
{
    int m, n;
    cin >> n >> m;
    vector<string> strs;
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        strs.push_back(row);
    }
    map<pair<int, int>, int> watched;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            watched.insert(make_pair(make_pair(i, j), 0));
        }
    }
    stack<pair<int, int>> s;
    s.push(make_pair(0, 0));
    int res = 0;
    while (s.size())
    {
        pair<int, int> top = s.top();
        int crow = top.first;
        int ccol = top.second;
        if (crow == n - 1 && ccol == m - 1)
        {
            if (res == 0)
            {
                res = solution(s);
            }
            else
            {
                res = min(res, solution(s));
            }
        }
        map<pair<int, int>, int>::iterator it = watched.find(top);
        if (it->second == 0)
        {
            if (crow < n - 1 && strs[crow + 1][ccol] != '*')
            {
                s.push(make_pair(crow + 1, ccol));
                it->second = 1;
                continue;
            }
            else
            {
                it->second = 1;
            }
        }
        if (it->second == 1)
        {
            if (crow < n - 1 && ccol < m - 1 && strs[crow + 1][ccol + 1] != '*')
            {
                s.push(make_pair(crow + 1, ccol + 1));
                it->second = 2;
                continue;
            }
            else
            {
                it->second = 2;
            }
        }
        if (it->second == 2)
        {
            if (ccol < m - 1 && strs[crow][ccol + 1] != '*')
            {
                s.push(make_pair(crow, ccol + 1));
                it->second = 3;
                continue;
            }
            else
            {
                it->second = 3;
            }
        }
        s.pop();
    }
    cout << res << endl;
    system("pause");
    return 0;
}