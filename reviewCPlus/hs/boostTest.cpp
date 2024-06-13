#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

int main()
{
    string s = "abcd,efg;hijlmn:opqrst/uvwxyz";
    vector<string> res;
    split(res, s, is_any_of(",:;/"));
    for (auto str : res)
    {
        cout << str << endl;
    }
    system("pause");
    return 0;
}