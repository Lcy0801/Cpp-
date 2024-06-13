#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <functional>
using namespace std;

struct Node
{
    char ch;
    int val;
    Node *left;
    Node *right;
    Node(char ch, int v) : ch(ch), val(v), left(nullptr), right(nullptr){};
    Node(int v, Node *left, Node *right) : val(v), left(left), right(right){};
    bool operator>(const Node &node) const
    {
        return this->val > node.val;
    }
};

void huffmanEncoding(const string &str, string &res)
{
    // 统计字符出现的频率
    unordered_map<char, int> dict;
    for (auto ch : str)
    {
        auto it = dict.find(ch);
        if (it == dict.end())
        {
            dict.insert(make_pair(ch, 1));
        }
        else
        {
            it->second += 1;
        }
    }
    // 将出现频率作为权重构造节点插入优先队列
    priority_queue<Node, vector<Node>, greater<Node>> q;
    for (auto kv : dict)
    {
        Node node(kv.first, kv.second);
        q.push(node);
    }

    while (q.size() > 1)
    {
        Node left = q.top();
        q.pop();
        Node right = q.top();
        q.pop();
        Node node(left.val + right.val, &left, &right);
        q.push(node);
    }
    Node root = q.top();
    // 深度优先遍历树
    stack<Node *> s;
    unordered_map<char, string> codeDict;
    string path = "";
    s.push(&root);
    while (s.size())
    {
        Node *top = s.top();
        if (top->left && top->left->val)
        {
            s.push(top->left);
            path.push_back('0');
        }
        else if (top->right && top->right->val)
        {
            s.push(top->right);
            path.push_back('1');
        }
        else
        {
            if (!top->left && !top->right)
            {
                codeDict.insert(make_pair(top->ch, path));
            }
            s.pop();
            top->val = 0;
            path.pop_back();
        }
    }
    for (auto ch : str)
    {
        res += codeDict[ch];
    }
}

int main()
{
    // string str = "aaa bb cccc dd e";
    // string res;
    // huffmanEncoding(str, res);
    // cout << res << endl;
    int a = 1;
    int b = 2;
    const int *x = &a;
    x = &b;
    system("pause");
    return 0;
}