#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    int level;
};


void bfsTree(Node * root, vector<vector<int>> & res)
{
    int levelMax = 0;
    queue<Node *> q;
    q.push(root);
    vector<pair<int,int>> seen;
    seen.push_back(make_pair(root->level,root->value));
    while (q.size())
    {
        Node *node = q.front();
        q.pop();
        if(node->left != NULL)
        {
            q.push(node->left);
            seen.push_back(make_pair(node->left->level,node->left->value));
            levelMax = node->left->level;
        }
        if(node->right!=NULL)
        {
            q.push(node->right);
            seen.push_back(make_pair(node->right->level, node->right->value));
            levelMax = node->right->level;
        }
    }
    // 初始化res
    res.reserve(levelMax + 1);
    for (int i = 0; i <= levelMax;i++)
    {
        res[i] = vector<int>();
    }
    int n = seen.size();
    for (int i = 0; i < n;i++)
    {
        int level = seen[i].first;
        int value = seen[i].second;
        res[level].push_back(value);
    }
    return;
}
