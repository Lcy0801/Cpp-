#include <iostream>
#include <map>
using namespace std;


int main()
{
    // 遍历数组
    int s[] = {1, 2, 3, 4, 5};
    for(int i:s)
    {
        cout << i << endl;
    }
    // 遍历容器
    map<string, int> m;
    m.insert(make_pair("A", 1));
    m.insert(make_pair("B", 2));
    m.insert(make_pair("C", 3));
    m.insert(make_pair("D", 4));
    m.insert(make_pair("E", 5));
    m.insert(make_pair("F", 6));
    for(auto item:m)
    {
        cout << item.first << "\t" << item.second << endl;
    }

    system("pause");
    return 0;
}