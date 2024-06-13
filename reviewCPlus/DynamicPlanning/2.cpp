/*
问题描述
有一组数字如3 34 4  12 5 2现要求判断能否从中随机选取一组数字使其之和等于s，输出True/False

问题分析
f(i)表示从前i个数中选取,使其之和等于s
状态转移方程/递归体
f(i,s)=f(i-1,s-vi) //选取第i个数字
f(i,s)=f(i-1,s) //不选取第i个数字
特殊情况
若存在数组中的数字都是正整数的前提，则当vi>s是，第i个数字一定不能选取，此时f(i,s) = f(i-1,s)

递归终止条件
f(i,0)从前i个数字选取使其之和为0，这表明之前选取的数之和已经为s，一定为True
f(0,s) 若v[0]=s则为True 否则为False
*/

#include <iostream>
#include <vector>
using namespace std;
// 递归写法
bool SSS_rec(const vector<int> &v, int index, int s)
{
    if (s == 0)
        return true;
    if (index == 0)
        return v[0] == s;
    if (v[index] > s)
        return SSS_rec(v, index - 1, s);
    else
        return SSS_rec(v, index - 1, s) || SSS_rec(v, index - 1, s - v[index]);
}
// 非递归写法
bool SSS(const vector<int> &v, int s)
{
    // 初始化状态矩阵
    int n = v.size();
    int state[n][s + 1];
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j <= s;j++)
        {
            state[i][j] = 0;
        }
    }
    if (v[0] <= s)
        state[0][v[0]] = 1;
    for (int i = 0; i < n; i++)
        state[i][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= s;j++)
        {
            if(v[i]>j)
            {
                state[i][j] = state[i - 1][j];
            }
            else
            {
                state[i][j] = state[i - 1][j] || state[i - 1][j - v[i]];
            }
        }
    }
    return state[n-1][s];
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(34);
    v.push_back(4);
    v.push_back(12);
    v.push_back(5);
    v.push_back(2);
    int s = 1;
    // 递归
    // bool flag = SSS_rec(v, v.size() - 1, s);
    // 非递归
    bool flag = SSS(v, s);
    cout << flag << endl;
    system("pause");
    return 0;
}