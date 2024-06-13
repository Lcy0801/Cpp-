#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

int solution(vector<int> &nums, int n)
{
    stack<int> nc;
    while (n)
    {
        nc.push(n % 10);
        n /= 10;
    }
    int L = nc.size();
    int maxV = 0;
    for (auto num : nums)
    {
        maxV = max(num, maxV);
    }
    bool flag = true;
    int res = 0;
    for (int i = 0; i < L; i++)
    {
        int v = nc.top();
        nc.pop();
        if (!flag)
        {
            res += maxV * pow(10, L - i - 1);
            continue;
        }
        int tmp = -1;
        if (i == L - 1)
        {
            for (auto num : nums)
            {
                if (num < v)
                {
                    tmp = max(tmp, num);
                }
            }
        }
        else
        {
            for (auto num : nums)
            {
                if (num <= v)
                {
                    tmp = max(tmp, num);
                }
            }
        }
        if (tmp != -1)
        {
            res += tmp * pow(10, L - i - 1);
        }
        else if (i == L - 1)
        {
            return -1;
        }
        flag = tmp == v;
    }
    return res;
}

int main()
{
    vector<int> nums;
    nums.push_back(6);
    nums.push_back(8);
    int n = 300;
    int res = solution(nums, n);
    cout << res << endl;
    system("pause");
    return 0;
}