#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    unordered_map<int, vector<pair<int, int>>> sums;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int v1 = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            int v2 = nums[j];
            int sum = v1 + v2;
            if (sums.find(sum) != sums.end())
            {
                sums[sum].push_back(make_pair(i, j));
            }
            else
            {
                sums[sum] = vector<pair<int, int>>(1, make_pair(i, j));
            }
        }
    }
    while (!sums.empty())
    {
        unordered_map<int, vector<pair<int, int>>>::iterator it = sums.begin();
        int sum = it->first;
        int sum_ = target - sum;
        if (sums.find(sum_) == sums.end())
        {
            sums.erase(sum);
            continue;
        }
        vector<pair<int, int>> firstTwo = sums[sum];
        vector<pair<int, int>> lastTwo = sums[sum_];
        for (auto &firstPair : firstTwo)
        {
            for (auto &lastPair : lastTwo)
            {
                int index1 = firstPair.first;
                int index2 = firstPair.second;
                int index3 = lastPair.first;
                int index4 = lastPair.second;
                if (index1 == index3 || index1 == index4 || index2 == index3 || index2 == index4)
                {
                    continue;
                }
                vector<int> resi;
                resi.push_back(nums[index1]);
                resi.push_back(nums[index2]);
                resi.push_back(nums[index3]);
                resi.push_back(nums[index4]);
                sort(resi.begin(), resi.end(), less<int>());
                auto vecCompare = [&resi](vector<int> &resi_)
                { return resi[0] == resi_[0] && resi[1] == resi_[1] && resi[2] == resi_[2] && resi[3] == resi_[3]; };
                if (find_if(res.begin(), res.end(), vecCompare) == res.end())
                {
                    res.push_back(resi);
                }
            }
        }
        sums.erase(sum);
        sums.erase(sum_);
    }
    return res;
}

int main()
{
    int s[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
    vector<int> nums(s,s+180);
    // nums.push_back(1);
    // nums.push_back(0);
    // nums.push_back(-1);
    // nums.push_back(0);
    // nums.push_back(-2);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(2);
    int target = 200;
    auto res = fourSum(nums,target);
    for(auto &resi:res)
    {
        cout << resi[0] << "\t" << resi[1] << "\t" << resi[2] << "\t" << resi[3]<<endl;
    }
    system("pause");
    return 0;
}