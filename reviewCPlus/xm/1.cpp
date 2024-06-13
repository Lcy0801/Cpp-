#include <iostream>
using namespace std;

struct ListNode
{
    int v;
    ListNode *next;
    ListNode(int x) : v(x), next(nullptr){};
};

class List
{
private:
    ListNode *head;

public:
    List(ListNode *node) : head(node){};
    List(){};
    void push_back(int val)
    {
        ListNode *node = new ListNode(val);
        if (!head)
        {
            head = node;
            return;
        }
        ListNode *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = node;
        return;
    }
    void del_node(int val)
    {
        if (!head)
            return;
        ListNode *last = nullptr;
        ListNode *current = head;
        while (current)
        {
            if (current->v != val)
            {
                last = current;
                current = current->next;
                continue;
            }
            if (last)
            {
                last->next = current->next;
                delete current;
                current = current->next;
            }
            else
            {
                head = current->next;
                delete current;
                current = head;
            }
        }
        return;
    }
};