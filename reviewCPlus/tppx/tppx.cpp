#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> aMatrix(numCourses, vector<int>(numCourses, 0));
        vector<int> penetrations(numCourses, 0);
        for (auto prereq : prerequisites)
        {
            int courseNo1 = prereq[0];
            int courseNo2 = prereq[1];
            aMatrix[courseNo2][courseNo1] = 1;
            penetrations[courseNo1]++;
        }
        vector<int> res;
        while (res.size() != numCourses)
        {
            bool flag = false;
            for (int i = 0; i < numCourses; i++)
            {
                if (penetrations[i] != 0)
                    continue;
                flag = true;
                res.push_back(i);
                penetrations[i] = -1;
                for (int j = 0; j < numCourses; j++)
                {
                    if (aMatrix[i][j])
                    {
                        penetrations[j]--;
                    }
                }
                break;
            }
            if (!flag)
                break;
        }
        return res.size() == numCourses;
    }
};

int main()
{
    vector<vector<int>> prerequisites;
    vector<int> prereq;
    prereq.push_back(1);
    prereq.push_back(0);
    prerequisites.push_back(prereq);
    bool res = Solution().canFinish(2, prerequisites);
    return 0;
}