#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

void heapify(vector<int> &nums, int L, int no)
{
    if (no >= L)
        return;
    while (true)
    {
        int left = 2 * no + 1;
        int right = 2 * no + 2;
        int max = no;
        if (left < L && nums[left] > nums[max])
        {
            max = left;
        }
        if (right < L && nums[right] > nums[max])
        {
            max = right;
        }
        if (max == no)
            return;
        int tmp = nums[max];
        nums[max] = nums[no];
        nums[no] = tmp;
        no = max;
    }
    return;
}

void heapSort(vector<int> &nums)
{
    int N = nums.size();
    for (int i = N - 1; i >= 0; i--)
    {
        heapify(nums, N, i);
    }
    int l = N;
    while (l > 1)
    {
        int tmp = nums[0];
        nums[0] = nums[l - 1];
        nums[l - 1] = tmp;
        heapify(nums, l - 1, 0);
        l--;
    }
}

class Print
{
public:
    void operator()(int v)
    {
        cout << v << "\t";
    }
};

int main()
{
    vector<int> nums;
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < 10; i++)
    {
        nums.push_back(rand() % 10);
    }
    heapSort(nums);
    for_each(nums.begin(),nums.end(),Print());
    system("pause");
    return 0;
}