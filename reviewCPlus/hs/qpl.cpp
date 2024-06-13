#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permutation(int n)
{
    if (n == 1)
    {
        vector<vector<int>> res;
        res.push_back(vector<int>(1, 1));
        return res;
    }
    vector<vector<int>> resn_1 = permutation(n - 1);
    vector<vector<int>> resn;
    for (auto pn_1 : resn_1)
    {
        for (int i = 0; i < n; i++)
        {
            vector<int> pn(pn_1.begin(), pn_1.end());
            auto it = pn.begin();
            for (int j = 0; j < i; j++)
            {
                it++;
            }
            pn.insert(it, n);
            resn.push_back(pn);
            it++;
        }
    }
    return resn;
}

int main()
{
    vector<vector<int>> res = permutation(5);
    // for (auto pn : res)
    // {
    //     for (auto v : pn)
    //     {
    //         cout << v << "\t";
    //     }
    //     cout << endl;
    // }
    cout << res.size() << endl;
    system("pause");
    return 0;
}