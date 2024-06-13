#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> s;
    s.push(nums2[0]);
    unordered_map<int, int> m;
    int n = nums2.size();
    for (int i = 1; i < n; i++)
    {
        if (nums2[i] > s.top())
        {
            do
            {
                m.insert(make_pair(s.top(), nums2[i]));
                s.pop();
            } while (s.size() && s.top() < nums2[i]);
        }
        s.push(nums2[i]);
    }
    while (s.size())
    {
        m.insert(make_pair(s.top(), -1));
        s.pop();
    }
    vector<int> res;
    for (int i = 0; i < nums1.size(); i++)
    {
        res.push_back(m.at(nums1[i]));
    }
    return res;
}