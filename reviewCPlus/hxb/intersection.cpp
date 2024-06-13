#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> s1;
    for (vector<int>::iterator it = nums1.begin(); it != nums1.end();it++)
    {
        s1.insert(*it);
    }
    vector<int> res;
    for (vector<int>::iterator it = nums2.begin(); it != nums2.end();it++)
    {
        if(s1.find(*it)!=s1.end())
        {
            res.push_back(*it);
            s1.erase(*it);
        }
    }
    return res;
}