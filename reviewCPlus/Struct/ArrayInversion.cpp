#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

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
    vector<int> vs;
    for (int i = 0; i < 10; i++)
    {
        vs.push_back(rand() % 10);
    }
    for_each(vs.begin(), vs.end(), Print());
    cout << endl;
    auto arrayInversion = [&vs](int start, int end)
    {
        while (start < end)
        {
            int tmp = vs[start];
            vs[start] = vs[end];
            vs[end] = tmp;
            start++;
            end--;
        }
        return;
    };
    arrayInversion(0, 9);
    arrayInversion(0, 6);
    arrayInversion(7, 9);
    for_each(vs.begin(), vs.end(), Print());
    cout << endl;
    system("pause");
    return 0;
}
