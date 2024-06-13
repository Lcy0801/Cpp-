#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool car_in_out(const vector<int> &carIns, const vector<int> &carOuts)
{
    int n = carOuts.size();
    for (int i = 0; i < n - 1; i++)
    {
        int carNo = carOuts[i];
        int carNoNext = carOuts[i + 1];
        int carNoIn = -1;
        int carNoNextIn = -1;
        for (int j = 0; j < n; j++)
        {
            if (carIns[j] == carNo)
            {
                carNoIn = j;
                break;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (carIns[j] == carNoNext)
            {
                carNoNextIn = j;
                break;
            }
        }
        if (carNoIn < carNoNextIn)
            continue;
        for (int j = carNoNextIn + 1; j < carNoIn; j++)
        {
            int carNoMid = carIns[j];
            int carOutIndex;
            for (int k = 0; k < n; k++)
            {
                if (carOuts[k] == carNoMid)
                {
                    carOutIndex = k;
                    break;
                }
            }
            if (carOutIndex > i + 1)
                return false;
        }
    }
    return true;
}

int main()
{
    int m, n;
    cin >> n >> m;
    vector<bool> flags;
    vector<int> carIns;
    for (int i = 0; i < n; i++)
    {
        int carIn;
        cin >> carIn;
        carIns.push_back(carIn);
    }
    for (int i = 0; i < m; i++)
    {
        vector<int> carOuts;
        for (int j = 0; j < n; j++)
        {
            int carOut;
            cin >> carOut;
            carOuts.push_back(carOut);
        }
        bool flag = car_in_out(carIns, carOuts);
        flags.push_back(flag);
    }
    for (int i = 0; i < m; i++)
    {
        if (flags[i])
            cout << "Yes"
                 << "\t";
        else
            cout << "No"
                 << "\t";
    }
    system("pause");
    return 0;
}