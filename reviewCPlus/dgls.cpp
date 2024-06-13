#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
using namespace std;

// 求point3到过point1和point2的直线的距离
// 点到直线距离计算公式：https://baike.baidu.com/item/%E7%82%B9%E5%88%B0%E7%9B%B4%E7%BA%BF%E8%B7%9D%E7%A6%BB/8673346?fr=aladdin
double point_to_line_dist(vector<double> point1, vector<double> point2, vector<double> point3)
{
    double dx = point2[0] - point1[0];
    double dy = point2[1] - point1[1];
    if (dx == 0)
    {
        return abs(point3[0] > point1[0]);
    }
    double k = dy / dx;
    double b = point1[1] - k * point1[0];
    double dist = abs(k * point3[0] - point3[1] + b) / sqrt(k * k + 1);
    return dist;
}

// 道格拉斯曲线简化算法
vector<vector<double>> dgls(vector<vector<double>> points, double threshold)
{
    set<int> resIndexs;
    int n = points.size();
    resIndexs.insert(0);
    resIndexs.insert(n - 1);
    queue<pair<int, int>> q;
    q.push(make_pair(0, n - 1));
    while (q.size())
    {
        int start = q.front().first;
        int end = q.front().second;
        q.pop();
        double dist;
        for (int i = start; i <= end; i++)
        {
            dist = point_to_line_dist(points[start], points[end], points[i]);
            if (dist > threshold)
            {
                resIndexs.insert(i);
                q.push(make_pair(start, i));
                q.push(make_pair(i, end));
                break;
            }
        }
    }
    vector<vector<double>> res;
    for (auto index : resIndexs)
    {
        res.push_back(points[index]);
    }
    return res;
}
