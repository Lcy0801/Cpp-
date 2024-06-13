#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<int, set<int>> tree;
    tree.reserve(n);
    for (int i = 0; i < n; i++)
    {
        tree[i] = set<int>();
    }
    int edgesNum;
    cin >> edgesNum;
    for (int i = 0; i < edgesNum; i++)
    {
        int start, end;
        cin >> start >> end;
        tree[start].insert(end);
    }
    unordered_set<int> blocks;
    int blocksNum;
    cin >> blocksNum;
    for (int i = 0; i < blocksNum; i++)
    {
        int blockNo;
        cin >> blockNo;
        blocks.insert(blockNo);
    }
    vector<int> res;
    unordered_set<int> seen;
    stack<int> s;
    s.push(0);
    seen.insert(0);
    while (s.size())
    {
        int nodeNo = s.top();
        if(tree[nodeNo].size()==0)
        {
            break;
        }
        bool flag = true;
        for(int childNo:tree[nodeNo])
        {
            if(seen.find(childNo)==seen.end()&&blocks.find(childNo)==blocks.end())
            {
                s.push(childNo);
                seen.insert(childNo);
                flag = false;
                break;
            }
        }
        if(flag)
        {
            s.pop();
        }
    }
    while (s.size())
    {
        res.push_back(s.top());
        s.pop();
    }
    int l = res.size();
    if(l==0)
    {
        cout << "NULL";
    }    
    else
    {
        while(true)
        {
            int no = res.back();
            cout << no;
            res.pop_back();
            if(res.size())
            {
                cout << "->";
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}
