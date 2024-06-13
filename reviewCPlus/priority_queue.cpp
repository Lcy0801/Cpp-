#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

struct Node
{
    int no;   // 节点序号
    int dist; // 起点到当前节点的最近距离
};

class NodeCompare
{
public:
    bool operator()(Node n1, Node n2)
    {
        return n1.dist > n2.dist;
    }
};

void Dijikstra(int n, const map<pair<int, int>, int> &ls, int start, vector<vector<int>> &res)
{
    // 已经走过的节点容器
    map<int, int> walked;
    // 初始化parent列表
    for (int i = 0; i < n; i++)
    {
        res.push_back(vector<int>(2, -1));
    }
    res[start][1] = 0;
    priority_queue<Node, vector<Node>, NodeCompare> pq;
    // 理清节点之间的连接关系
    vector<set<int>> nlr;
    nlr.resize(n);
    for (int i = 0; i < n; i++)
    {
        nlr.push_back(set<int>());
    }
    for (map<pair<int, int>, int>::const_iterator it = ls.begin(); it != ls.end(); it++)
    {
        int lstart = (*it).first.first;
        int lend = (*it).first.second;
        nlr[lstart].insert(lend);
        nlr[lend].insert(lstart);
    }
    Node startNode;
    startNode.no = start;
    startNode.dist = 0;
    pq.push(startNode);
    while (pq.size())
    {
        Node currentNode = pq.top();
        int cNo = currentNode.no;
        if (walked.find(cNo) != walked.end())
        {
            pq.pop();
            continue;
        }
        set<int> lns = nlr[cNo];
        for (set<int>::iterator it = lns.begin(); it != lns.end(); it++)
        {
            if (walked.find(*it) != walked.end())
                continue;
            pair<int, int> lKey = cNo < *it ? make_pair(cNo, *it) : make_pair(*it, cNo);
            int ld = ls.at(lKey);
            Node nextNode;
            nextNode.no = *it;
            nextNode.dist = ld + currentNode.dist;
            pq.push(nextNode);
            // 更新父节点的关系 parent
            if (res[nextNode.no][1] == -1 || res[nextNode.no][1] > nextNode.dist)
            {
                res[nextNode.no][0] = cNo;
                res[nextNode.no][1] = nextNode.dist;
            }
        }
        // 弹出队头元素
        pq.pop();
        walked.insert(make_pair(cNo, currentNode.dist));
    }
    return;
}

int main()
{
    // 节点数量
    int pn, ln;
    // cout << "请输入节点数量:";
    // cin >> pn;
    pn = 6;
    // cout << "请输入边数:";
    // cin >> ln;
    ln = 8;
    map<pair<int, int>, int> ls;
    // for (int i = 0; i < ln; i++)
    // {
    //     int start, end, ld;
    //     cin >> start >> end >> ld;
    //     pair<int, int> lKey = start > end ? make_pair(end, start) : make_pair(start, end);
    //     ls.insert(make_pair(lKey, ld));
    // }
    ls.insert(make_pair(make_pair(0, 1), 5));
    ls.insert(make_pair(make_pair(0, 2), 1));
    ls.insert(make_pair(make_pair(1, 2), 2));
    ls.insert(make_pair(make_pair(1, 3), 1));
    ls.insert(make_pair(make_pair(2, 3), 4));
    ls.insert(make_pair(make_pair(2, 4), 8));
    ls.insert(make_pair(make_pair(3, 4), 3));
    ls.insert(make_pair(make_pair(3, 5), 6));
    vector<vector<int>> res;
    Dijikstra(pn, ls, 0, res);
    cout << endl;
    for (int i = 0; i < pn; i++)
    {
        stack<int> least_road;
        int index = i;
        while (res[index][0] != -1)
        {
            least_road.push(index);
            index = res[index][0];
        }
        least_road.push(index);
        while (least_road.size())
        {
            cout << least_road.top() << "\t";
            least_road.pop();
        }
        cout << endl;
        cout << "最短路径长度为：" << res[i][1] << endl;
    }
    system("pause");
    return 0;
}
