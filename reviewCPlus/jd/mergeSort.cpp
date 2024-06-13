#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> & nums,int left,int right)
{
    int l = right - left;
    if(!l)
        return;
    int mid = (left+right)/2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    left = 0;
    right = mid + 1;
    vector<int> res;
    res.reserve(nums.size());
    while(left<=mid && right<nums.size())
    {
        if(nums[left]<nums[right])
        {
            res.push_back(nums[left]);
            left++;
        }
        else
        {
            res.push_back(nums[right]);
            right++;
        }
    }
    while (left<=mid)
    {
        res.push_back(nums[left]);
        left++;
    }
    while(right<nums.size())
    {
        res.push_back(nums[right]);
        right++;
    }
    return
}
