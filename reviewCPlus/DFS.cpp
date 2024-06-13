#include <iostream>
// 深度优先遍历基于的数据结构栈
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    const int n = 6;
    map<char, int> vertxs;
    vertxs.insert(make_pair('A', 2));
    vertxs.insert(make_pair('B', 3));
    vertxs.insert(make_pair('C', 4));
    vertxs.insert(make_pair('D', 4));
    vertxs.insert(make_pair('E', 2));
    vertxs.insert(make_pair('F', 1));
    map<char, char *> graph;
    char vA[] = {'B', 'C'};
    char vB[] = {'A', 'C', 'D'};
    char vC[] = {'A', 'B', 'D', 'E'};
    char vD[] = {'B', 'C', 'E', 'F'};
    char vE[] = {'C', 'D'};
    char vF[] = {'D'};
    graph.insert(pair<char, char *>('A', vA));
    graph.insert(pair<char, char *>('B', vB));
    graph.insert(pair<char, char *>('C', vC));
    graph.insert(pair<char, char *>('D', vD));
    graph.insert(pair<char, char *>('E', vE));
    graph.insert(pair<char, char *>('F', vF));
    stack<char> s;
    s.push('C');
    vector<char> seen;
    seen.push_back('C');
    while (s.size())
    {
        char vertex = s.top();
        char *vertexsLink = graph.at(vertex);
        int nLink = vertxs.at(vertex);
        bool flag = false;
        for (int i = 0; i < nLink; i++)
        {
            if (find(seen.begin(), seen.end(), vertexsLink[i]) == seen.end())
            {
                s.push(vertexsLink[i]);
                seen.push_back(vertexsLink[i]);
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            s.pop();
        }
    }
    cout << "当前遍历的节点：" << endl;
    for (vector<char>::iterator it = seen.begin(); it != seen.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}