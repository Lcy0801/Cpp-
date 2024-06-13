#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int v)
{
    cout << v << "\t";
}

int solution(vector<int> &s1, vector<int> &s2)
{
    int res = 0;
    int L = s1.size();
    if (L == 0)
        return res;
    for (int l = 1; l <= L; l++)
    {
        vector<vector<int>> arr1s;
        vector<vector<int>> arr2s;
        for (int i = 0; i < L; i++)
        {
            int j = i + l - 1;
            if (j > (L - 1))
                break;
            vector<int> arr1(s1.begin() + i, s1.begin() + j + 1);
            for_each(arr1.begin(), arr1.end(), print);
            cout << endl;
            if (find(arr2s.begin(), arr2s.end(), arr1) == arr2s.end())
            {
                res++;
                arr1s.push_back(arr1);
                // for_each(arr1.begin(), arr1.end(), print);
                // cout << endl;
            }
            vector<int> arr2(s2.begin() + i, s2.begin() + j + 1);
            if (find(arr1s.begin(), arr1s.end(), arr2) == arr1s.end())
            {
                res++;
                arr2s.push_back(arr2);
                // for_each(arr1.begin(), arr1.end(), print);
                // cout << endl;
            }
        }
    }
    return res;
}

int main()
{
    int n = 4;
    // cin >> n;
    vector<int> s1;
    // int v;
    // while (cin >> v)
    // {
    //     s1.push_back(v);
    //     if (s1.size() == n)
    //         break;
    // }
    s1.push_back(1);
    s1.push_back(2);
    s1.push_back(3);
    s1.push_back(4);
    vector<int> s2;
    s2.push_back(2);
    s2.push_back(3);
    s2.push_back(1);
    s2.push_back(4);
    // while (cin >> v)
    // {
    //     s2.push_back(v);
    //     if (s2.size() == n)
    //         break;
    // }
    int res = solution(s1, s2);
    cout << res << endl;
    system("pause");
    return 0;
}
