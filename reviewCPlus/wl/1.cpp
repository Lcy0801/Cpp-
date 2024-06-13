#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    nums.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        nums.push_back(v);
    }
    int left = 0;
    int right = n - 1;
    long long res = (right - left) * min(nums[left], nums[right]);
    while (left < right)
    {
        if (nums[left] < nums[right])
        {
            int index = left;
            while (nums[index]<=nums[left])
            {
                index++;
            }
            long long tmp = (right - index) * min(nums[right], nums[index]);
            res = max(res, tmp);
            left = index;
        }
        else
        {
            int index = right;
            while (nums[index]<=nums[right])
            {
                index--;
            }
            long long tmp = (index - left) * min(nums[index], nums[left]);
            res = max(res, tmp);
            right = index;
        }
    }
    cout << res << endl;
    return 0;
}