#include <iostream>
#include <set>
#include <vector>
using namespace std;

long long soultion(int m, int n, int k)
{
    if (m > n)
    {
        int t = m;
        m = n;
        n = t;
    }
    set<long long> res;
    auto setToVector = [&res]()
    {
        vector<long long> v(res.begin(), res.end());
        return v.back();
    };
    int i = 1;
    while (i <= n)
    {
        int x = 1;
        int y = i;
        while (x <= m && y >= 1)
        {
            res.insert(x * y);
            if ((res.size() - k) == 0)
            {
                return setToVector();
            }
            x++;
            y--;
        }
        i++;
    }
    i = 2;
    while (i <= m)
    {
        int x = i;
        int y = n;
        while (x <= n && y >= 1)
        {
            res.insert(x * y);
            if ((res.size() - k) == 0)
            {
                return setToVector();
            }
            x++;
            y--;
        }
        i++;
    }
    return 0;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    set<long long> s;
    long long res= soultion(m,n,k);
    printf("%lld",res);
}