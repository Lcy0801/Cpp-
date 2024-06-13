#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Print
{
public:
    void operator()(int v)
    {
        cout << v << "\t";
    }
};

class Solution
{
private:
    vector<int> res;
    vector<vector<int>> allRes;
    void backTracing(vector<int> &candidates, int target, int index)
    {
        if (target == 0)
        {
            allRes.push_back(res);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
                continue;
            res.push_back(candidates[i]);
            backTracing(candidates, target - candidates[i], i);
            res.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backTracing(candidates, target, 0);
        return allRes;
    }
};

int main()
{
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(4);
    candidates.push_back(7);
    Solution().combinationSum(candidates, 7);
    system("pause");
    return 0;
}