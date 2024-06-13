#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        vector<pair<int, int>> watched;
        int maxArea = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    continue;
                pair<int, int> node = make_pair(i, j);
                if (find(watched.begin(), watched.end(), node) != watched.end())
                    continue;
                queue<pair<int, int>> q;
                q.push(node);
                int area = 0;
                vector<pair<int, int>> seen;
                seen.push_back(node);
                while (q.size())
                {
                    pair<int, int> cNode = q.front();
                    int ci = cNode.first;
                    int cj = cNode.second;
                    if (ci - 1 >= 0 && grid[ci - 1][cj] && find(seen.begin(), seen.end(), make_pair(ci - 1, cj)) == seen.end())
                    {
                        q.push(make_pair(ci - 1, cj));
                        seen.push_back(make_pair(ci - 1, cj));
                    }
                    if (ci + 1 <= m - 1 && grid[ci + 1][cj] && find(seen.begin(), seen.end(), make_pair(ci + 1, cj)) == seen.end())
                    {
                        q.push(make_pair(ci + 1, cj));
                        seen.push_back(make_pair(ci + 1, cj));
                    }
                    if (cj - 1 >= 0 && grid[ci][cj - 1] && find(seen.begin(), seen.end(), make_pair(ci, cj - 1)) == seen.end())
                    {
                        q.push(make_pair(ci, cj - 1));
                        seen.push_back(make_pair(ci, cj - 1));
                    }
                    if (cj + 1 <= n - 1 && grid[ci][cj + 1] && find(seen.begin(), seen.end(), make_pair(ci, cj + 1)) == seen.end())
                    {
                        q.push(make_pair(ci, cj + 1));
                        seen.push_back(make_pair(ci, cj + 1));
                    }
                    q.pop();
                    area++;
                    watched.push_back(cNode);
                }
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};

int main()
{
    vector<int> v1 = {1, 2, 3};
    cout << v1.size() << endl;
    v1.push_back(1);
    vector<int> v2;
    v2.push_back(2);
    if (v1 == v2)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
    system("pause");
    return 0;
}