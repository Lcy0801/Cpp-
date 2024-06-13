#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int res = 0;
    int n = heights.size();
    if (n == 0)
    {
        return res;
    }
    auto calArea = [heights](int start, int end)
    {
        if (start > end)
        {
            return 0;
        }
        int minv = heights[start];
        for (int i = start + 1; i <= end; i++)
        {
            minv = min(minv, heights[i]);
        }
        return (end - start + 1) * minv;
    };
    res = calArea(0, n - 1);
    queue<pair<int, int>> q;
    q.push(make_pair(0, n - 1));
    while (q.size())
    {
        int left = q.front().first;
        int right = q.front().second;
        q.pop();
        int minv = heights[left];
        vector<int> minIndexs = {left};
        for (int i = left + 1; i <= right; i++)
        {
            if (heights[i] < minv)
            {
                minIndexs.clear();
                minIndexs.push_back(i);
                minv = heights[i];
            }
            else if (heights[i] == minv)
            {
                minIndexs.push_back(i);
            }
        }
        minIndexs.insert(minIndexs.begin(), left - 1);
        minIndexs.push_back(right+1);
        for (int i = 0; i < minIndexs.size();i++)
        {
            int start = minIndexs[i] + 1;
            int end = minIndexs[i + 1] - 1;
            res = max(res, calArea(start, end));
            if(start<end)
            {
                q.push(make_pair(start, end));
            }
        }
    }
    return res;
}