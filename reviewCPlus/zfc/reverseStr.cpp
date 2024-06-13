#include <iostream>
#include <string>
using namespace std;
string reverseStr(string s, int k) {
    int l = s.length();
    int N = l / (2*k);
    int n = l % (2*k);
    char tmp;
    int left, right;
    for (int i = 0; i < N;i++)
    {
         left = i * 2 * k;
         right = left + k - 1;
        while (left<right)
        {
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
    if(n>k)
    {
         left = N * 2 * k;
         right = left + k - 1;
    }
    else
    {
         left = N * 2 * k;
         right = left + n - 1;
    }
    while (left<right)
    {
        tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
    return s;
}