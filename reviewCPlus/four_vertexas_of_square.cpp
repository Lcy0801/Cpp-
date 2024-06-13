#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<double>> four_vertexs_of_square(const vector<vector<double>> &points, double d)
{
    vector<double> p1 = points[0];
    vector<double> p2 = points[1];
    vector<double> p3 = points[2];
    vector<double> p4 = points[3];
    auto vector_subtract = [](vector<double> start, vector<double> end)
    {
        vector<double> v;
        v.push_back(end[0] - start[0]);
        v.push_back(end[1] - start[1]);
        v.push_back(end[2] - start[2]);
        return v;
    };
    auto vector_dot = [](vector<double> v1, vector<double> v2)
    {
        return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
    };
    auto vector_multiply = [](vector<double> v, double f)
    {
        vector<double> res = {v[0] * f, v[1] * f, v[2] * f};
        return res;
    };
    vector<double> v1_2 = vector_subtract(p1, p2);
    vector<double> v1_3 = vector_subtract(p1, p3);
    vector<double> v1_4 = vector_subtract(p1, p4);
    vector<double> vx, vy;
    if (vector_dot(v1_2, v1_3) == 0)
    {
        vx = v1_2;
        vy = v1_3;
    }
    else if (vector_dot(v1_2, v1_2) > vector_dot(v1_3, v1_3))
    {
        vx = v1_3;
        vy = v1_4;
    }
    else
    {
        vx = v1_2;
        vy = v1_4;
    }
    vector<double> vx_norm;
    double vx_dist = sqrt(vector_dot(vx, vx));
    vx_norm = vector_multiply(vx, 1 / vx_dist);
    vector<double> vy_norm;
    double vy_dist = sqrt(vector_dot(vy, vy));
    vy_norm = vector_multiply(vy, 1 / vy_dist);
    vector<double> v1_ = vector_subtract(p1, vector_multiply(vx_norm, d));
    vector<double> v1 = vector_subtract(v1_, vector_multiply(vy_norm, d));
    vector<double> v2 =vector_subtract(v1,vector_multiply(vx_norm,-(vx_dist+d+d)));
    vector<double> v3 =vector_subtract(v2,vector_multiply(vy_norm,-(vy_dist+d+d)));
    vector<double> v4 =vector_subtract(v1,vector_multiply(vy_norm,-(vy_dist+d+d)));
    vector<vector<double>> res = {v1, v2, v3, v4};
    return res;
}

int main()
{
    vector<int> x;
    x = {1, 2, 3};
    for (auto i : x)
    {
        cout << i << endl;
    }
    system("pause");
    return 0;
}