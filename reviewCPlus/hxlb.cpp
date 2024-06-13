#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(!head)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        while (true)
        {
            if (fast->next && fast->next->next)
                fast = fast->next->next;
            else
                return nullptr;
            if (slow->next)
                slow = slow->next;
            else
                return nullptr;
            // 追逐点
            if (slow == fast)
                break;
            ;
        }
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{
    ListNode *p = nullptr;
    if (p)
        cout << 123;
    else
        cout << 321;
    system("pause");
    return 0;
}