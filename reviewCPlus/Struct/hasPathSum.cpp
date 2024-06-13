#include <iostream>
#include <stack>
#include <unordered_set>
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        stack<TreeNode *> s;
        unordered_set<TreeNode *> popedNodes;
        s.push(root);
        int currentSum = root->val;
        while (s.size())
        {
            TreeNode *top = s.top();
            if (top->left && popedNodes.find(top->left) == popedNodes.end())
            {
                s.push(top->left);
                currentSum += top->left->val;
            }
            else if (top->right && popedNodes.find(top->right) == popedNodes.end())
            {
                s.push(top->right);
                currentSum += top->right->val;
            }
            else
            {
                if (!top->left && !top->right && currentSum == targetSum)
                {
                    return true;
                }
                else
                {
                    s.pop();
                    currentSum -= top->val;
                }
            }
        }
        return false;
    }
};