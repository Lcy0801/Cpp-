#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<long long> &nums, int L, int no)
{
    if (no >= L)
        return;
    while (true)
    {
        int left = 2 * no + 1;
        int right = 2 * no + 2;
        int min = no;
        if (left < L && nums[left] < nums[min])
        {
            min = left;
        }
        if (right < L && nums[right] < nums[min])
        {
            min = right;
        }
        if (min == no)
            return;
        int tmp = nums[min];
        nums[min] = nums[no];
        nums[no] = tmp;
        no = min;
    }
    return;
}

void heapSort(vector<long long> &nums, int k)
{
    int N = nums.size();
    for (int i = N - 1; i >= 0; i--)
    {
        heapify(nums, N, i);
    }
    int l = N;
    while (l > (N - k))
    {
        long long tmp = nums[0];
        nums[0] = nums[l - 1];
        nums[l - 1] = tmp;
        heapify(nums, l - 1, 0);
        l--;
    }
}

int main()
{
    string s;
    cin >> s;
    int k = atoi(s.substr(0, 1).c_str());
    int L = s.length();
    int index = 1;
    vector<long long> nums;
    while (index * 2 < L)
    {
        nums.push_back(atoi(s.substr(index * 2, 1).c_str()));
        index++;
    }
    heapSort(nums, k);
    string res = "";
    for (int i = 0; i < k; i++)
    {
        if(i!=k-1)
        {
            cout << nums[nums.size() - i - 1] << ",";
        }
        else
        {
            cout << nums[nums.size() - i - 1];
        }
    }
    system("pause");
    return 0;
}