/*
问题描述：
有一组数字如4 1 1 9 1,现要求从中随机选取一组互不相邻的数字使得选取的数字之和最大
分析：
优化目标： max(sum)
约束：不相邻

f(i)表示从前i个数中选取得到的最大值，则有如下递推关系
f(i)=f(i-2)+v(i)  选第i个数
f(i)=f(i-1) 不选第i个数
f(1)=v(1)
f(2)=max(v(1),v(2))
*/

#include <iostream>
#include <vector>
using  namespace std;

// SSM:sum selected max
void SSM(const vector<int>s,int & smax,vector<int> &index)
{
    int n = s.size();
    // 最大和
    vector<int> res(n,0);
    // 选择方案
    vector<vector<int>> indexs(n,vector<int>());
    res[0] = s[0];
    indexs[0].push_back(0);
    if(n==1)
    {
        index.push_back(0);
        smax = s[0];
        return;
    }
    if(s[0]>=s[1])
    {
        res[1] = s[0];
        indexs[1].push_back(0);
        index.push_back(0);
        smax = s[0];
    }
    else
    {
        res[1] = s[1];
        indexs[1].push_back(1);
        index.push_back(1);
        smax = s[1];
    }
    if(n==2)
        return;
    for (int i = 2; i < n;i++)
    {
        int r1 = s[i] + res[i - 2];
        int r2 = res[i - 1];
        if(r1>=r2)
        {
            res[i] = r1;
            indexs[i]=vector<int>(indexs[i-2]);
            indexs[i].push_back(i);
        }
        else
        {
            res[i] = r2;
            indexs[i] = vector<int>(indexs[i - 1]);
        }
    }
    index = indexs[n - 1];
    smax = res[n - 1];
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vs;
    for (int i = 0; i < n;i++)
    {
        int v;
        cin >> v;
        vs.push_back(v);
    }
    for (int j = 1; j < n;j++)
    {
        vector<int>vs1 = 
    }
}


