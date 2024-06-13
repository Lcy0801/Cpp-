#include <vector>
#include <numeric>
using namespace std;

class Solution
{
private:
    vector<int> res;
    vector<vector<int>> allRes;
    void backTracing(int n, int k, int startIndex)
    {
        int sum = accumulate(res.begin(), res.end(), 0);
        if (res.size() == k)
        {
            if (sum == n)
                allRes.push_back(res);
            return;
        }
        for (int i = startIndex; i <= n - sum && i < 10; i++)
        {
            res.push_back(i);
            backTracing(n, k, i + 1);
            res.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backTracing(n, k, 1);
        return allRes;
    }
};
