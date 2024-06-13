#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end(), less<int>());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int a = nums[i];
        if (a > 0 || (i >= 1 && a == nums[i - 1]))
        {
            continue;
        }
        int bindex = i + 1;
        int cindex = n - 1;
        int b, c, sum;
        while (bindex < cindex)
        {
            b = nums[bindex];
            c = nums[cindex];
            sum = a + b + c;
            if (sum == 0)
            {
                if (bindex == i + 1 || b != nums[bindex - 1])
                {
                    vector<int> resi;
                    resi.push_back(a);
                    resi.push_back(b);
                    resi.push_back(c);
                    res.push_back(resi);
                }
                bindex++;
                cindex--;
            }
            else if (sum > 0)
            {
                cindex--;
            }
            else
            {
                bindex++;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> s;
    for (int i = 0; i < 10; i++)
    {
        s.push_back(rand() % 10);
    }
    sort(s.begin(), s.end(), less<int>());
    for (int v : s)
    {
        cout << v << endl;
    }
    system("pause");
    return 0;
}