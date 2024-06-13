#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    map<int, int> m;
    vector<int> res;
    for (int i = 0; i < nums.size();i++)
    {
        int n1 = nums[i];
        int n2 = target - n1;
        if(m.find(n2)!=m.end())
        {
            res.push_back(m.at(n2));
            res.push_back(i);
            return res;
        }
        m.insert(make_pair(n1, i));
    }
    return res;
}
