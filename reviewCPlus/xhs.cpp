#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Person
{
public:
    string m_name;
    int m_age;
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
        cout << "构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "析构函数调用" << endl;
    }
};

void delete_person(Person *p)
{
    if(p!=nullptr)
    {
        cout << p->m_name << ":" << p->m_age << "岁" << endl;
    }
    return;
}

int main()
{
    shared_ptr<Person> p1 = make_shared<Person>(Person("lcy",23),delete_person);
    p1.reset();
    system("pause");
    return 0;
}