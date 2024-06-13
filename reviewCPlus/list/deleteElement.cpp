#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode();
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

ListNode *removeElements(ListNode *head, int val)
{
    if (!head)
        return nullptr;
    ListNode *last = nullptr;
    ListNode *cur = head;
    while (cur)
    {
        if (cur->val == val)
        {
            if (last)
            {
                last->next = cur->next;
                delete cur;
                cur = last->next;
            }
            else
            {
                head = cur->next;
                delete cur;
                cur = head;
            }
        }
        else
        {
            last = cur;
            cur = cur->next;
        }
    }
    return head;
}