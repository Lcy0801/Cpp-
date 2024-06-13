#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int minStart = INT32_MAX, maxEnd = 0;
    int start, end;
    vector<pair<int,int>> ranges;
    ranges.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        minStart = min(minStart, start);
        maxEnd = max(end, maxEnd);
        ranges.push_back(make_pair(start, end));
    }
    int res = 0;
    for (int i = minStart; i <= maxEnd;i++)
    {
        int k = 0;
        for (vector<pair<int, int>>::iterator it = ranges.begin(); it != ranges.end();it++)
        {
            int start = it->first;
            int end = it->second;
            if(start<= i && end>=i)
            {
                k++;
            }
            if(k==2)
            {
                break;
            }
        }
        if(k==0)
        {
            res += 1;
        }
        else if(k==1)
        {
            res += 3;
        }
        else
        {
            res += 4;
        }
        
    }
    cout << res;
    system("pause");
    return 0;
}