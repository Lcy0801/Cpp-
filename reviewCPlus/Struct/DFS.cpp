#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int v) : value(v), left(nullptr), right(nullptr){};
};

vector<int> dfs(Node *root)
{
    vector<int> res;
    if (!root)
        return res;
    stack<Node *> s;
    unordered_set<Node *> popedNodes;
    s.push(root);
    res.push_back(root->value);
    while (s.size())
    {
        Node *top = s.top();
        if (top->left && popedNodes.find(top->left)==popedNodes.end())
        {
            s.push(top->left);
            res.push_back(top->left->value);
        }
        else if (top->right && popedNodes.find(top->right)==popedNodes.end())
        {
            s.push(top->right);
            res.push_back(top->right->value);
        }
        else
        {
            s.pop();
            popedNodes.insert(top);
        }
    }
    return res;
}

int main()
{
    
}