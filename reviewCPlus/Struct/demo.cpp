#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Person
{
public:
    string m_name;
    int *m_age;
    Person(string name, int age)
    {
        m_name = name;
        m_age = new int(age);
    }
    Person(Person &p)
    {
        this->m_name = p.m_name;
        this->m_age = p.m_age;
    }
    Person(Person &&p)
    {
        this->m_name = p.m_name;
        this->m_age = p.m_age;
        p.m_age = nullptr;
    }
    Person& operator=(Person &&p)
    {
        this->m_name = p.m_name;
        this->m_age = p.m_age;
        p.m_age = nullptr;
        return *this;
    }
    Person(){};
};

int main()
{
    Person A("a", 1);
    Person B(A);
    Person C;
    C = B; 
    system("pause");
    return 0;
}