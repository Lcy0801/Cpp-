#include <iostream>
#include <unordered_set>
using namespace std;

bool isHappy(int n)
{
    unordered_set<int> s;
    while (true)
    {
        int n_ = 0;
        while (n)
        {
            int m = n % 10;
            n_ += m * m;
            n /= 10;
        }
        n = n_;
        if(n==1)
        {
            return true;
        }
        else
        {
            if(s.find(n)!=s.end())
            {
                return false;
            }
            else
            {
                s.insert(n);
            }
        }
    }
}
