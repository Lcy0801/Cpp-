#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<list<int>> getPermutations(int n)
{
    if (n == 1)
    {
        vector<list<int>> res;
        res.push_back(list<int>(1, 1));
        return res;
    }
    vector<list<int>> resN_1 = getPermutations(n - 1);
    vector<list<int>> resN;
    for (vector<list<int>>::iterator it = resN_1.begin(); it != resN_1.end(); it++)
    {
        list<int> item = *it;
        for (int i = 0; i < n; i++)
        {
            list<int> item_(item);
            list<int>::iterator it_ = item_.begin();
            for (int j = 0; j < i; j++)
            {
                it_++;
            }
            item_.insert(it_, n);
            resN.push_back(item_);
        }
    }
    return resN;
}

class Mycompare
{
public:
    bool operator()(list<int> v1, list<int> v2)
    {
        if (v1.size() != v2.size())
        {
            return true;
        }
        int n = v1.size();
        list<int>::iterator it1 = v1.begin();
        list<int>::iterator it2 = v2.begin();
        while (it1 != v1.end() && it2 != v2.end())
        {
            int e1 = *it1;
            int e2 = *it2;
            if (e1 > e2)
            {
                return false;
            }
            else if (e1 < e2)
            {
                return true;
            }
            it1++;
            it2++;
        }
        return true;
    }
};

int main()
{
    vector<list<int>> res = getPermutations(7);
    sort(res.begin(), res.end(), Mycompare());
    for (vector<list<int>>::iterator it = res.begin(); it != res.end(); it++)
    {
        list<int> item = *it;
        for (list<int>::iterator it_ = item.begin(); it_ != item.end(); it_++)
        {
            cout << *it_ << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}