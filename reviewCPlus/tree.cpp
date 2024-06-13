#include <iostream>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
using namespace std;

struct Node
{
    Node *parent = NULL;
    Node *leftChild = NULL;
    Node *rightChild = NULL;
    int value = 0;
};

// 基于vector容器中数据的输入顺序生成一棵树
Node *generateTree(const vector<int> s)
{
    int n = s.size();
    if (n == 0)
        return NULL;
    // 初始化根节点
    Node *root = new Node();
    root->value = s[0];
    for (int i = 1; i < n; i++)
    {
        int v = s[i];
        Node *currentNode = root;
        while (true)
        {
            if (v <= currentNode->value)
            {
                if (currentNode->leftChild == NULL)
                {
                    Node *newNode = new Node();
                    newNode->parent = currentNode;
                    newNode->value = v;
                    currentNode->leftChild = newNode;
                    break;
                }
                else
                {
                    currentNode = currentNode->leftChild;
                }
            }
            else
            {
                if (currentNode->rightChild == NULL)
                {
                    Node *newNode = new Node();
                    newNode->parent = currentNode;
                    newNode->value = v;
                    currentNode->rightChild = newNode;
                    break;
                }
                else
                {
                    currentNode = currentNode->rightChild;
                }
            }
        }
    }
    return root;
}

void firstPrintTree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->value << "\t";
    firstPrintTree(root->leftChild);
    firstPrintTree(root->rightChild);
    return;
}

void middlePrintTree(Node *root)
{
    if (root == NULL)
        return;
    middlePrintTree(root->leftChild);
    cout << root->value << "\t";
    middlePrintTree(root->rightChild);
    return;
}

void lastPrintTree(Node *root)
{
    if (root == NULL)
        return;
    lastPrintTree(root->leftChild);
    lastPrintTree(root->rightChild);
    cout << root->value << "\t";
    return;
}

// 二叉树广度优先遍历
void bfsTree(Node *root, vector<int> &tree)
{
    queue<Node *> q;
    q.push(root);
    tree.push_back(root->value);
    while (q.size())
    {
        Node *node = q.front();
        if (node->leftChild)
        {
            q.push(node->leftChild);
            tree.push_back(node->leftChild->value);
        }
        if (node->rightChild)
        {
            q.push(node->rightChild);
            tree.push_back(node->rightChild->value);
        }
        q.pop();
    }
    return;
}

// 二叉树深度优先遍历
void dfsTree(Node *root, vector<int> &tree)
{
    stack<Node *> s;
    s.push(root);
    tree.push_back(root->value);
    map<Node *, int> seen;
    while (s.size())
    {
        Node *node = s.top();
        if (node->leftChild && seen.find(node->leftChild) == seen.end())
        {
            s.push(node->leftChild);
            tree.push_back(node->leftChild->value);
            seen.insert(make_pair(node->leftChild, node->leftChild->value));
            continue;
        }
        if (node->rightChild && seen.find(node->rightChild) == seen.end())
        {
            s.push(node->rightChild);
            tree.push_back(node->rightChild->value);
            seen.insert(make_pair(node->rightChild, node->rightChild->value));
            continue;
        }
        s.pop();
    }
    return;
}

void destoryTree(Node *root)
{
    // 必须先释放叶子节点再释放根节点，因此采用后续遍历的方式
    if (root == NULL)
        return;
    destoryTree(root->leftChild);
    destoryTree(root->rightChild);
    delete root;
    return;
}

// 统计一颗二叉树中叶子节点的数量
void nodeNum(Node *root, int &num)
{
    if (root == NULL)
    {
        return;
    }
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        num += 1;
    }
    nodeNum(root->leftChild, num);
    nodeNum(root->rightChild, num);
}

int main()
{
    vector<int> s;
    srand((unsigned int)time(NULL));
    cout << "生成节点" << endl;
    for (int i = 0; i < 10; i++)
    {
        int v = rand() % 10;
        cout << v << "\t";
        s.push_back(v);
    }
    cout << endl;
    Node *root = generateTree(s);
    cout << "先序遍历" << endl;
    firstPrintTree(root);
    cout << endl;
    cout << "中序遍历" << endl;
    middlePrintTree(root);
    cout << endl;
    cout << "后序遍历" << endl;
    lastPrintTree(root);
    cout << endl;
    cout << "广度优先遍历" << endl;
    vector<int> vbfs;
    bfsTree(root, vbfs);
    for (vector<int>::iterator it = vbfs.begin(); it != vbfs.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
    cout << "深度优先遍历" << endl;
    vector<int> vdfs;
    dfsTree(root, vdfs);
    for (vector<int>::iterator it = vdfs.begin(); it != vdfs.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
    // 统计二叉树中叶子节点的数量
    int num = 0;
    nodeNum(root, num);
    cout << "叶子节点的数量：" << num << endl;
    // 释放二叉树占用的堆内存
    destoryTree(root);
    system("pause");
    return 0;
}