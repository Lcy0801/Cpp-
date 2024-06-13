#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if(!root)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool dirFlag = true;
        while (q.size())
        {
            queue<TreeNode *> tmp;
            deque<int> vs;
            while (q.size())
            {
                if(dirFlag)
                {
                    vs.push_back(q.front()->val);
                }
                else
                {
                    vs.push_front(q.front()->val);
                }
                if (q.front()->left)
                {
                    tmp.push(q.front()->left);
                }
                if (q.front()->right)
                {
                    tmp.push(q.front()->right);
                }
                q.pop();
            }
            res.push_back(vector<int>(vs.begin(), vs.end()));
            q = tmp;
            dirFlag = !dirFlag;
        }
        return res;
    }
};