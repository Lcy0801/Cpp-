#include <iostream>
#include <string>
using namespace std;

string reverseLeftWords(string s, int n)
{
    int left, right;
    char ch;
    left = 0;
    right = n - 1;
    // 翻转前n个字符
    while (left < right)
    {
        ch = s[left];
        s[left] = s[right];
        s[right] = ch;
        left++;
        right--;
    }
    // 翻转第n+1个到最后一个字符
    left = n;
    right = s.size() - 1;
    while (left < right)
    {
        ch = s[left];
        s[left] = s[right];
        s[right] = ch;
        left++;
        right--;
    }
    // 翻转整个字符串
    left = 0;
    right = s.size() - 1;
    while (left < right)
    {
        ch = s[left];
        s[left] = s[right];
        s[right] = ch;
        left++;
        right--;
    }
    return s;
}
