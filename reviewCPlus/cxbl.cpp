#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr){};
};

void solution(Node *root, vector<vector<int>> &res)
{
    queue<Node *> q;
    q.push(root);
    while (q.size())
    {
        queue<Node *> tmp;
        vector<int> nums;
        while (q.size())
        {
            Node *node = q.front();
            nums.push_back(node->val);
            if (node->left)
            {
                tmp.push(node->left);
            }
            if (node->right)
            {
                tmp.push(node->right);
            }
            q.pop();
        }
        q = tmp;
        res.push_back(nums);
    }
    return;
}
