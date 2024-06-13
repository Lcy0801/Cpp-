#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_POWER 100

bool taskCompare(pair<int, int> task1, pair<int, int> task2)
{
    int end1 = task1.second - task1.first;
    int end2 = task2.second - task2.first;
    return end1 > end2;
}

int main()
{
    vector<pair<int, int>> tasks;
    string task;
    string taskList;
    cin >> taskList;
    stringstream ss(taskList);
    while (getline(ss, task, ','))
    {
        int index = task.find(':');
        int consume = atoi(task.substr(0, index).c_str());
        int begin = atoi(task.substr(index + 1).c_str());
        tasks.push_back(make_pair(consume, begin));
    }
    sort(tasks.begin(), tasks.end(), taskCompare);
    int res = 0;
    int current = res;
    for (auto task : tasks)
    {
        int consume = task.first;
        int begin = task.second;
        if (current >= begin)
        {
            current -= consume;
        }
        else
        {
            res += begin - current;
            current = begin - consume;
        }
        if (res > MAX_POWER)
        {
            res = -1;
            break;
        }
    }
    cout << res << endl;
    system("pause");
    return 0;
}