#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

string target = "";

bool compare(string s)
{
    int index = s.find(target);
    if (index < 0)
        return false;
    if (index == 0)
        return false;
    if (s.length() - index == target.length())
        return false;
    return true;
}

int main()
{
    // int n;
    // cin >> n;
    // vector<string> ss;
    // ss.reserve(n);
    // for (int i = 0; i < n; i++)
    // {
    //     string s;
    //     cin >> s;
    //     ss.push_back(s);
    // }
    // vector<string> css;
    // css.reserve(n * n);
    // for (int i = 0; i < n; i++)
    // {
    //     string start = ss[i];
    //     for (int j = 0; j < n; j++)
    //     {
    //         string end = ss[j];
    //         start.append(end);
    //         css.push_back(start);
    //     }
    // }
    // set<string> res;
    // int N = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     target = ss[i];
    //     auto it = find_if(css.begin(), css.end(), compare);
    //     if(it!=ss.end())
    //     {
    //         N++;
    //         res.insert(target);
    //     }
    // }
    // cout << N << endl;
    // for(auto s:res)
    // {
    //     cout << s << endl;
    // }
    string ss = "123";
    string s = "0";
    ss.append(s);
    // int index = ss.find(s);
    cout << ss << endl;
    system("pause");
    return 0;
}