#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool car_in_out(map<int, int> &in, vector<int> &out)
{
    int n = out.size();
    for (int i = 1; i < n; i++)
    {
        int carNo = out[i];
        int carNoBefore = out[i - 1];
        int carIn = in[carNo];
        int carBeforeIn = in[carNoBefore];
        if (carBeforeIn < carIn)
            return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    vector<bool> flags;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        map<int, int> in;
        vector<int> out;
        int carNo;
        for (int j = 0; j < num; j++)
        {
            cin >> carNo;
            in.insert(make_pair(carNo, j));
        }
        int carOut;
        for (int j = 0; j < num; j++)
        {
            cin >> carOut;
            out.push_back(carOut);
        }
        bool flag = car_in_out(in, out);
        flags.push_back(flag);
    }
    for (int i = 0; i < N; i++)
    {
        if (flags[i])
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
    }
    return 0;
}