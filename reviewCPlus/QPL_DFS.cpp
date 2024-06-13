#include <iostream>
#include <stack>
#include <set>
#include <vector>
using namespace std;

vector<stack<int>> getPermutations(int n)
{
    vector<stack<int>> res;
    int K = 1;
    for (int i = 1; i < n; i++)
    {
        K *= i;
    }
    for (int i = 1; i <= n; i++)
    {

        stack<int> s;
        s.push(i);
        int lastPop = 0;
        set<int> candidateQueue;
        for (int j = 1; j <= n; j++)
        {
            candidateQueue.insert(j);
        }
        candidateQueue.erase(i);
        int k = 0;
        while (k < K)
        {
            if (candidateQueue.size())
            {
                s.push(*candidateQueue.begin());
                candidateQueue.erase(candidateQueue.begin());
                if (lastPop)
                {
                    candidateQueue.insert(lastPop);
                    lastPop = 0;
                }
            }
            else
            {
                if (lastPop)
                {
                    candidateQueue.insert(lastPop);
                }
                lastPop = s.top();
                if (s.size() == n)
                {
                    res.push_back(s);
                    k++;
                }
                s.pop();
            }
        }
    }
    return res;
}

int main()
{
    vector<stack<int>> res = getPermutations(4);
    cout << "全排列一共有" << res.size() << "种" << endl;
    for (vector<stack<int>>::iterator it = res.begin(); it != res.end(); it++)
    {
        stack<int> s = *it;
        vector<int> v;
        while (s.size())
        {
            v.push_back(s.top());
            s.pop();
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            cout << v.at(i) << "\t";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}