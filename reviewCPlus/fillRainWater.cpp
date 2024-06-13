#include <iostream>
#include <vector>
using namespace std;

int fillRainWater(const vector<int> &heights)
{
    int water = 0;
    int n = heights.size();
    if (n <= 2)
    {
        return 0;
    }
    for (int i = 1; i < n - 1; i++)
    {
        int height = heights[i];
        int lmax = 0;
        int rmax = 0;
        for (int j = 0; j < i; j++)
        {
            lmax = heights[j] >= lmax ? heights[j] : lmax;
        }
        for (int k = i + 1; k < n; k++)
        {
            rmax = heights[k] > rmax ? heights[k] : rmax;
        }
        if (height < rmax && height < lmax)
        {
            water += (min(lmax, rmax) - height);
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