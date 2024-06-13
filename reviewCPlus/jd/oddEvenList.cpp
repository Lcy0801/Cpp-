#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even0 = head->next;
        while (true)
        {
            if (!even)
            {
                break;
            }
            odd->next = even->next;
            if(!even->next)
            {
                break;
            }
            odd = even->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = even0;
        return head;
    }
};