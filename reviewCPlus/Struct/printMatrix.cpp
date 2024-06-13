#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(const vector<vector<int>> &matrix)
    {
        vector<int> res;
        // 获取行列数
        int row = matrix.size();
        if(row==0)
            return res;
        int col = matrix[0].size();
        res.reserve(row * col);
        int N = row > col ? (col + 1) / 2 : (row + 1) / 2;
        for (int i = 0; i < N; i++)
        {
            int rowSatrt = i;
            int rowEnd = row - i - 1;
            int colStart = i;
            int colEnd = col - i - 1;
            if (rowSatrt == rowEnd)
            {
                for (int j = colStart; j <= colEnd; j++)
                {
                    res.push_back(matrix[rowSatrt][j]);
                }
            }
            else if (colStart == colEnd)
            {
                for (int j = rowSatrt; j <= rowEnd; j++)
                {
                    res.push_back(matrix[j][colStart]);
                }
            }
            else
            {
                for (int j = colStart; j <= colEnd; j++)
                {
                    res.push_back(matrix[rowSatrt][j]);
                }
                for (int j = rowSatrt + 1; j < rowEnd; j++)
                {
                    res.push_back(matrix[j][colEnd]);
                }
                for (int j = colEnd; j >= colStart; j--)
                {
                    res.push_back(matrix[rowEnd][j]);
                }
                for (int j = rowEnd - 1; j > rowSatrt; j--)
                {
                    res.push_back(matrix[j][colStart]);
                }
            }
        }
        return res;
    }
};