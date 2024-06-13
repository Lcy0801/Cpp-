#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end(), less<int>());
    for (int i = 0; i < n - 2; i++)
    {
        int a = nums[i];
        if(a>0 || (i>=1 && a==nums[i-1]))
        {
            continue;
        }
        set<int> vs;
        for (int j = i + 1; j < n; j++)
        {
            int b = nums[j];
            int c = -a - b;
            if (vs.find(c) != vs.end())
            {
                vector<int> resi;
                resi.push_back(a);
                resi.push_back(b);
                resi.push_back(c);
                res.push_back(resi);
                vs.erase(b);
            }
            else
            {
                vs.insert(b);
            }
        }
    }
}
