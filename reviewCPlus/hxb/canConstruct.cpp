#include <iostream>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine) 
{
    unordered_map<char, int> ransomNotek_n;
    unordered_map<char, int> magazinek_n;
    for(auto ch:ransomNote)
    {
        if(ransomNotek_n.find(ch)!=ransomNotek_n.end())
        {
            ransomNotek_n[ch]++;
        }
        else
        {
            ransomNotek_n[ch] = 1;
        }
    }
    for(auto ch:magazine)
    {
        if(magazinek_n.find(ch)!=magazinek_n.end())
        {
            magazinek_n[ch]++;
        }
        else
        {
            magazinek_n[ch] = 1;
        }
    }
    for(auto &ch_n:ransomNotek_n )
    {
        char ch = ch_n.first;
        int num = ch_n.second;
        if(magazinek_n.find(ch)==magazinek_n.end())
        {
            return false;
        }
        else if (magazinek_n[ch]<num)
        {
            return false;
        }
    }
    return true;
} 