#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int res = 0;
    int rowN = grid.size();
    int colN = grid[0].size();
    for (int i = 0; i < rowN; i++)
    {
        for (int j = 0; j < colN; j++)
        {
            int v = grid[i][j];
            if (v == 0 || v == -1)
            {
                continue;
            }
            int area = 0;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            area++;
            grid[i][j] = -1;
            while (q.size())
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if(col!=0 && grid[row][col-1]==1)
                {
                    q.push(make_pair(row, col - 1));
                    grid[row][col - 1] = -1;
                    area++;
                }
                if (col != colN - 1 && grid[row][col + 1] == 1)
                {
                    q.push(make_pair(row, col + 1));
                    grid[row][col + 1] = -1;
                    area++;
                }
                if(row!=0 && grid[row-1][col]==1)
                {
                    q.push(make_pair(row - 1, col));
                    grid[row - 1][col] = -1;
                    area++;
                }
                if (row != rowN - 1 && grid[row + 1][col] == 1)
                {
                    q.push(make_pair(row + 1, col));
                    grid[row + 1][col] = -1;
                    area++;
                }
            }
            res = max(res, area);
        }
    }
    return res;
}