#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>
using namespace std;

void quickSort(vector<int> &s, int k)
{
    int n = s.size();
    if (n <= 1)
        return;
    queue<pair<int, int>> q;
    q.push(make_pair(0, n - 1));
    while (q.size())
    {
        pair<int, int> currentIndex = q.front();
        int start = currentIndex.first;
        int end = currentIndex.second;
        int v = s[start];
        while (start < end)
        {
            while (end > start)
            {
                if (s[end] < v)
                {
                    s[start] = s[end];
                    break;
                }
                end--;
            }
            while (start < end)
            {
                if (s[start] > v)
                {
                    s[end] = s[start];
                    break;
                }
                start++;
            }
        }
        s[start] = v;
        if (start == n - k)
        {
            cout << v << endl;
        }
        if (currentIndex.first < start)
        {
            q.push(make_pair(currentIndex.first, start - 1));
        }
        if (currentIndex.second > start)
        {
            q.push(make_pair(start + 1, currentIndex.second));
        }
        q.pop();
    }
    return;
}

class Print
{
public:
    void operator()(int v)
    {
        cout << v << "\t";
    }
};
int main()
{
    srand((unsigned int)time(nullptr));
    vector<int> s;
    for (int i = 0; i < 10; i++)
    {
        s.push_back(rand() % 10);
    }
    for_each(s.begin(), s.end(), Print());
    cout << endl;
    int k = rand() % 10 + 1;
    cout << k << endl;
    quickSort(s, k);
    for_each(s.begin(), s.end(), Print());
    cout << endl;
    system("pause");
    return 0;
}