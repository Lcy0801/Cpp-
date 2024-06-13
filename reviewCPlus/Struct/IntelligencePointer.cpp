#include <iostream>
#include <memory>
#include <string>
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
    }
    Person(const Person &p)
    {
        cout << "拷贝构造" << endl;
        this->m_name = p.m_name;
        this->m_age = p.m_age;
    }
    // Person(Person &&p)
    // {
    //     cout << "移动构造" << endl;
    //     this->m_name = p.m_name;
    //     this->m_age = p.m_age;
    // }
    ~Person()
    {
        cout << "析构函数调用了";
    }
};

void releaseFunc(Person *p)
{
    cout << p->m_name << endl;
    cout << p->m_age << endl;
    delete p;
    cout << "内存已经释放了" << endl;
}

Person getTmp()
{
    Person p("lcy", 23);
    return p;
}

int main()
{
    // shared_ptr<Person> p(new Person("lcy", 23),releaseFunc);
    // p.reset();
    // cout << p->m_name << endl;
    // cout << p.use_count() << endl;
    // unique_ptr<Person, decltype(&releaseFunc)> p1(new Person("lcy", 23), releaseFunc);
    // cout << p1->m_name << endl;
    // unique_ptr<Person> p2(p1.release());
    // cout << p2->m_name << endl;
    // p2.reset();
    // Person p1("lcy",23);
    // Person p2 = p1;
    // Person p3 = move(p1);
    Person p1= getTmp();
    system("pause");
    return 0;
}