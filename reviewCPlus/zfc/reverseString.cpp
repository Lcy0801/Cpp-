#include <vector>
#include <iostream>
using namespace std;
void reverseString(vector<char>& s) 
{
    int n = s.size();
    if(n==0)
    {
        return;
    }
    int left = 0;
    int right = n - 1;
    char tmp;
    while (left<right)
    {
        tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
    return;
}