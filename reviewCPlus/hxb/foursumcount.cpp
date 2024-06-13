#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    int n = nums1.size();
    // 统计前两个数组中两数之和的所有可能与次数
    unordered_map<int, int> sum1_2;
    for(auto v1:nums1)
    {
        for(auto v2:nums2)
        {
            int v1_2 = v1 + v2;
            if(sum1_2.find(v1_2)!=sum1_2.end())
            {
                sum1_2[v1_2]++;
            }
            else
            {
                sum1_2[v1_2] = 1;
            }
        }
    }
    unordered_map<int, int> sum3_4;
    for (auto v3 : nums3)
    {
        for (auto v4 : nums4)
        {
            int v3_4 = v3 + v4;
            if (sum3_4.find(v3_4) != sum3_4.end())
            {
                sum3_4[v3_4]++;
            }
            else
            {
                sum3_4[v3_4] = 1;
            }
        }
    }
    int res = 0;
    for(auto kv1_2:sum1_2)
    {
        int v1_2 = kv1_2.first;
        int num1_2 = kv1_2.second;
        if(sum3_4.find(-v1_2)!=sum3_4.end())
        {
            res += num1_2 * sum3_4[-v1_2];
        }
    }
    return res;
}
