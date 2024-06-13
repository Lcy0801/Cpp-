#include <iostream>
#include <memory>
using namespace std;

class Person
{
private:
    string m_name = "A";
    int m_age = 0;

public:
    Person(string name, int age) : m_name(name), m_age(age)
    {
        cout << "有参构造函数调用了" << endl;
    };
    Person()
    {
        cout << "构造函数调用了" << endl;
    }
    ~Person()
    {
        cout << m_name << "析构函数调用了" << endl;
    }
};

int main()
{
    auto p1 = Person();                                    // 自动类型推导
    shared_ptr<Person> p2 = make_shared<Person>(Person()); // 智能指针
    auto p3 = p2;
    cout << "引用的个数为：" << p2.use_count() << endl;
    p2 = make_shared<Person>(Person("Chaoying", 24));
    system("pause");
    return 0;
}