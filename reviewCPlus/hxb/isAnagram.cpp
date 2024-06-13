#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    int n1 = s.length();
    int n2 = t.length();
    if(n1!=n2)
        return false;
    unordered_map<char, int> smap;
    unordered_map<char,int> tmap;
    for (int i = 0; i < n1;i++)
    {
        char chs = s[i];
        char cht = t[i];
        unordered_map<char, int>::iterator its = smap.find(chs);
        unordered_map <char, int>::iterator itt = tmap.find(cht);
        if(its==smap.end())
            smap.insert(make_pair(chs, 1));
        else
            its->second++;
        if(itt==tmap.end())
            tmap.insert(make_pair(cht, 1));
        else
            itt->second++;
    }
    for (unordered_map<char, int>::iterator it = smap.begin(); it != smap.end();it++)
    {
        char key = it->first;
        int nums = it->second;
        if(tmap.find(key)==tmap.end())
            return false;
        else
        {
            int numt = tmap.at(key);
            if(numt!=nums)
                return false;
        }
    }

    return true;
}