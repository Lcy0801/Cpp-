#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr){};
};

bool isFT(Node *root)
{
    queue<Node *> q;
    q.push(root);
    bool flag = false;
    while (q.size())
    {
        Node *cNode = q.front();
        q.pop();
        if (cNode->left && cNode->right)
        {
            q.push(cNode->left);
            q.push(cNode->right);
        }
        else if (!cNode->left && cNode->right)
        {
            return false;
        }
        else
        {
            break;
        }
    }
    while (q.size())
    {
        Node *cnode = q.front();
        q.pop();
        if (!cnode->left && !cnode->right)
        {
            continue;
        }
        return false;
    }
    return true;
}
