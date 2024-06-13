#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;

void quickSort(vector<int> &nums)
{
    int l = nums.size();
    if (l <= 1)
        return;
    queue<pair<int, int>> q;
    q.push(make_pair(0, l - 1));
    while (q.size())
    {
        pair<int, int> index = q.front();
        int start = index.first;
        int end = index.second;
        int v = nums[start];
        while (start < end)
        {
            while (nums[end] >= v && end > start)
            {
                end--;
            }
            if (nums[end] < v)
            {
                nums[start] = nums[end];
            }
            while (nums[start] <= v && start < end)
            {
                start++;
            }
            if (nums[start] > v)
            {
                nums[end] = nums[start];
            }
        }
        nums[start] = v;
        if (q.front().first < start - 1)
        {
            q.push(make_pair(q.front().first, start - 1));
        }
        if (q.front().second > start + 1)
        {
            q.push(make_pair(start + 1, q.front().second));
        }
        q.pop();
    }
}

void quickSort2(vector<int> &nums, int start, int end)
{
    int left = start;
    int right = end;
    if (left >= right)
        return;
    int v = nums[left];
    while (left < right)
    {
        while (left < right && nums[right] >= v)
        {
            right--;
        }
        if (nums[right] < v)
        {
            nums[left] = nums[right];
        }
        while (left < right && nums[left] <= v)
        {
            left++;
        }
        if (nums[left] > v)
        {
            nums[right] = nums[left];
        }
    }
    nums[left] = v;
    quickSort2(nums, start, left - 1);
    quickSort2(nums, left + 1, end);
    return;
}

int main()
{
    srand((unsigned int)time(nullptr));
    vector<int> nums;
    for (int i = 0; i < 10; i++)
    {
        int v = rand() % 10;
        nums.push_back(v);
    }
    // quickSort(nums);
    quickSort2(nums, 0, nums.size() - 1);
    for (auto v : nums)
    {
        cout << v << "\t";
    }
    cout << endl;
    system("pause");
    return 0;
}