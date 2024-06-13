#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode() : val(0), left(nullptr), right(nullptr){};
    ListNode(int x) : val(x), left(nullptr), right(nullptr){};
    ListNode(int x, ListNode *left, ListNode *right) : val(x), left(left), right(right){};
};

void solution(ListNode *root, vector<int> &res)
{
    if (!root)
        return;
    queue<ListNode *> q;
    q.push(root);
    while (q.size())
    {
        ListNode *node = q.front();
        if (node->left)
        {
            q.push(node->left);
            res.push_back(node->left->val);
        }
        if (node->right)
        {
            q.push(node->right);
        }
        q.pop();
    }
    return;
}