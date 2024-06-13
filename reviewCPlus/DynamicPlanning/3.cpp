/*
动态规划 01背包问题
问题描述
有下列货物价值p1 p2 p3 p4 ………… pn，体积分别为v1 v2 v3 v4 ………… vn
背包的容量为V，如何选择货品才能使得所选货物的价值之和最高

问题分析
问题的复杂度在于货物的数量N，如果N=1或2，则很好判断，因此解题思路复杂问题简单化，找出不同数量货物解之间的关系
f(i,v)表示商品数量为i(i>=0,i=0表示第一件商品)，容量限制为V时可选货物价值和的最大值
状态转移方程 / 递归体
f(i,v)=f(i-1,V) 选择第i件商品
f(i,v)=f(i-1,V-vi)+pi 不选择第i件商品

边界条件 / 递归终止条件
f(0,V) = 0(v0 > V) / p0(v0<=V)
f(i,0) = 0
*/

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// 递归解法
/*
ps 商品价值
vs 商品体积
*/
int SSM(const vector<int> &ps, const vector<int> &vs, int index, int V)
{
    int n = ps.size();
    if (V == 0)
        return 0;
    if (index == 0)
    {
        return vs[0] > V ? 0 : ps[0];
    }
    if(vs[index] >V)
        return SSM(ps, vs, index - 1, V);
    else
        return max(SSM(ps, vs, index - 1, V), SSM(ps, vs, index - 1, V - vs[index]) + ps[index]);
}

// 非递归解法 dynamic planning
int SSM(vector<int> &ps, vector<int> &vs, int V)
{
    int n = ps.size();
    int state[n][V+1];
    // 初始化 背包的容积为0
    // V=0
    for (int i = 0; i < n;i++)
    {
        state[i][0] = 0;
    }
    // n=1 只有一件商品
    for (int j = 0; j <= V;j++)
    {
        state[0][j] = j >= vs[0] ? ps[0] : 0;
    }
    for (int i = 1; i < n;i++)
    {
        for (int j = 1; j <= V;j++)
        {
            if(vs[i]>j)
                state[i][j] = state[i - 1][j];
            else
                state[i][j] = max(state[i - 1][j], state[i - 1][j - vs[i]] + ps[i]);
        }
    }
    return state[n - 1][V];
}

// 测试
int main()
{
    vector<int> ps, vs;
    srand((unsigned int)time(NULL));
    int V = 10;
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        ps.push_back(rand() % 5 + 1);
        vs.push_back(rand() % 5 + 1);
        printf("第%d件商品的价格和体积:%d,%d\n", i + 1, ps[i], vs[i]);
    }
    int res_rec = SSM(ps, vs, n - 1, V);
    cout << "递归解法："<<res_rec << endl;
    int res = SSM(ps, vs,V);
    cout << "非递归解法：" << res << endl;
    system("pause");
    return 0;
}
