#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int s;
    cout << "输入一个整数：" << endl;
    cin >> s;
    for (int x = 0; x <= sqrt(s); x++)
    {
        double y = sqrt(s - pow(x, 2));
        double diff = abs((int)y - y);
        if(diff==0)
        {
            cout << x << "\t" << y << endl;
        }
    }
    system("pause");
    return 0;
}