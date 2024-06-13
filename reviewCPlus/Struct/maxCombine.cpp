#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Compare
{
public:
    bool operator()(int v1, int v2)
    {
        stack<int> vc1;
        while (v1)
        {
            vc1.push(v1 % 10);
            v1 = v1 / 10;
        }
        stack<int> vc2;
        while (v2)
        {
            vc2.push(v2 % 10);
            v2 = v2 / 10;
        }
        int c1 = 0, c2 = 0;
        while (vc1.size() || vc2.size())
        {
            if (vc1.size())
            {
                c1 = vc1.top();
                vc1.pop();
            }
            if (vc2.size())
            {
                c2 = vc2.top();
                vc2.pop();
            }
            if (c1 > c2)
            {
                return true;
            }
            else if (c1 < c2)
            {
                return false;
            }
        }
        return true;
    }
};

int combineMax(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    queue<pair<int, int>> q;
    q.push(make_pair(0, n - 1));
    while (q.size())
    {
        int start = q.front().first;
        int end = q.front().second;
        int v = nums[start];
        while (start < end)
        {
            while (end > start)
            {
                if (!Compare()(nums[end], v))
                {
                    nums[start] = nums[end];
                    break;
                }
                end--;
            }
            while (start < end)
            {
                if (!Compare()(v, nums[start]))
                {
                    nums[end] = nums[start];
                    break;
                }
                start++;
            }
        }
        nums[start] = v;
        if ((start - 1) > q.front().first)
        {
            q.push(make_pair(q.front().first, start - 1));
        }
        if ((start + 1) < q.front().second)
        {
            q.push(make_pair(start + 1, q.front().second));
        }
        q.pop();
    }
}

int main()
{
    return 0;
}