#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){};
    ListNode(int v) : val(v), next(nullptr){};
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr;
        // 虚拟头节点
        ListNode headBefore;
        headBefore.next = head;
        ListNode *lastBefore = &headBefore;
        ListNode *last = head;
        ListNode *current = head->next;
        while (current)
        {
            if (current->val != last->val)
            {
                lastBefore = last;
                last = current;
                current = current->next;
                continue;
            }
            last = deleteHeadDuplicates(last);
            if (!last)
            {
                lastBefore->next = nullptr;
                break;
            }
            lastBefore->next = last;
            current = last->next;
        }
        return headBefore.next;
    }
    ListNode *deleteHeadDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *current = head->next;
        if (current->val != head->val)
            return head;
        current = current->next;
        while (current)
        {
            if (current->val != head->val)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

ListNode *ArrayToList(int s[], int l)
{
    ListNode *head;
    ListNode *last;
    for (int i = 0; i < l; i++)
    {
        ListNode *current = new ListNode(s[i]);
        if (i == 0)
        {
            head = current;
        }
        else
        {
            last->next = current;
        }
        last = current;
    }
    return head;
}
int main()
{
    // int s[] = {1, 2, 3, 3, 4, 4, 5};
    // ListNode *head = ArrayToList(s, sizeof(s) / sizeof(int));
    // ListNode *res = Solution().deleteDuplicates(head);
    // while (res)
    // {
    //     cout << res->val << endl;
    //     res = res->next;
    // }
    string x = "123";
    char a = x[0];
    cout << atoi(&a) << endl;
    system("pause");
    return 0;
}