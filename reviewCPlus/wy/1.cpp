#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;

class Compare
{
public:
    bool operator()(pair<int, int> score1, pair<int, int> score2)
    {
        return score1.second >= score2.second;
    }
};

bool isGreat(vector<int> &cars, vector<int> &orders, vector<pair<int, int>> &scores)
{
    int m = cars[0];
    int j = cars[1];
    int k = cars[2];
    sort(scores.begin(), scores.end(), Compare());
    int carj = scores[j - 1].first;
    int cark = scores[k - 1].first;
    map<int, int> scoresMap;
    for (int i = 0; i < m; i++)
    {
        scoresMap.insert(scores[i]);
    }
    while (orders.size() != 1)
    {
        vector<int> res;
        for (int i = 0; i < orders.size() - 1; i += 2)
        {
            int car1 = orders[i];
            int car2 = orders[i + 1];
            if ((car1 == carj && car2 == cark) || (car1 == cark && car2 == carj))
                return true;
            int car1Score = scoresMap[car1];
            int car2Score = scoresMap[car2];
            if (car1Score >= car2Score)
            {
                res.push_back(car1);
            }
            else
            {
                res.push_back(car2);
            }
        }
        orders = res;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> cars;
        vector<int> orders;
        vector<pair<int,int>> scores;
        int m, j, k;
        cin >> m >> j >> k;
        cars.push_back(m);
        cars.push_back(j);
        cars.push_back(k);
        for (int x = 0; x < m; x++)
        {
            int order;
            cin >>order;
            orders.push_back(order);
        }
        for (int x = 0; x < m; x++)
        {
            int score;
            cin >> score;
            scores.push_back(make_pair(x + 1, score));
        }
        bool flag = isGreat(cars, orders, scores);
        if(flag)
        {
            cout << "YQST";
        }
        else
        {
            cout << "...";
        }
    }
    system("pause");
    return 0;
}