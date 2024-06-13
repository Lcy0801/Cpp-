#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<int> roadSegments(1000, 0);
        for (auto &trip : trips)
        {
            int num = trip[0];
            int from = trip[1];
            int to = trip[2];
            for (int i = from; i < to; i++)
            {
                roadSegments[i] += num;
            }
        }
        bool flag = true;
        for(auto v:roadSegments)
        {
            if(v>capacity)
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
};