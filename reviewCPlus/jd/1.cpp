#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

string solution(const string &str1, const string &str2)
{
    int l1 = str1.length();
    int l2 = str2.length();
    int index1 = l1 - 1;
    int index2 = l2 - 1;
    string res = "";
    int flag = 0;
    while (index1 >= 0 && index2 >= 0)
    {
        int num1 = str1[index1] == '1' ? 1 : 0;
        int num2 = str2[index2] == '1' ? 1 : 0;
        int num = num1 + num2 + flag;
        flag = num / 2;
        if (num % 2)
        {
            res = '1' + res;
        }
        else
        {
            res = '0' + res;
        }
        index1--;
        index2--;
    }
    while (index1 >= 0)
    {
        int num1 = str1[index1] == '1' ? 1 : 0;
        int num = num1 + flag;
        flag = num / 2;
        if (num == 1)
        {
            res = '1' + res;
        }
        else
        {
            res = '0' + res;
        }
        index1--;
    }
    while (index2 >= 0)
    {
        int num2 = str1[index2] == '1' ? 1 : 0;
        int num = num2 + flag;
        flag = num / 2;
        if (num == 1)
        {
            res = '1' + res;
        }
        else
        {
            res = '0' + res;
        }
        index2--;
    }
    if (flag)
    {
        res = '1' + res;
    }
    return res;
}

class Person
{
public:
    string m_name;
    int m_age;
    Person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }
    Person(){};
};

int main()
{
    string a = "11";
    string b = "1";
    vector<Person> persons;
    string res = solution(a, b);
    cout << res << endl;
    system("pause");
    return 0;
}
