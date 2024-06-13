#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "构造函数调用了" << endl;
    };
    ~Person()
    {
        cout << "析构函数调用了" << endl;
    }
};

struct Test
{
    float x=1;
    int y = 10;
};


int main()
{
    // Person *p1 = new Person();
    // delete p1;
    // // malloc返回的时万能指针，因此必须做强制类型转换
    // Person *p2 = (Person *)malloc(sizeof(Person));
    // free(p2);
    // Test t;
    // cout << t.x << endl;
    // cout << t.y << endl;
    // cout << 123 << endl;
    cout <<"你好" << endl;
    return 0;
} 