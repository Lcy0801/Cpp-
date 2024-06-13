#include <iostream>
#include <vector>
using namespace std;

int fillRainWater(const vector<int> &heights)
{
    int n = heights.size();
    // 左侧最大值
    int lmax = 0;
    vector<int> lmaxs;
    lmaxs.reserve(n);
    lmaxs[0] = lmax;
    for (int i = 0; i < n - 1; i++)
    {
        lmax = heights[i] >= lmax ? heights[i] : lmax;
        lmaxs[i + 1] = lmax;
    }
    // 右侧最大值
    int rmax = 0;
    vector<int> rmaxs;
    rmaxs.reserve(n);
    rmaxs[n - 1] = rmax;
    for (int i = n - 1; i > 0; i--)
    {
        rmax = heights[i] >= rmax ? heights[i] : rmax;
        rmaxs[i - 1] = rmax;
    }
    // 雨水总数
    int water = 0;
    for (int i = 1; i < n - 1;i++)
    {
        int h = heights[i];
        lmax = lmaxs[i];
        rmax = rmaxs[i];
        if(lmax > h && rmax > h )
        {
            water += min(lmax, rmax) - h;
        }
    }
    return water;
}

int main()
{
    int heights[] = {4, 2, 0, 3, 2, 5};
    vector<int> hs;
    for (int i = 0; i < sizeof(heights) / sizeof(heights[0]); i++)
    {
        hs.push_back(heights[i]);
    }
    int water = fillRainWater(hs);
    cout << "能够接到的雨水总量为：" << water << endl;
    system("pause");
    return 0;
}