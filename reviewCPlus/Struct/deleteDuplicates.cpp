#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr){};
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *cNode = head->next;
        ListNode *lNode = head;
        while (cNode)
        {
            if (lNode->val == cNode->val)
            {
                lNode->next = cNode->next;
            }
            else
            {
                lNode = cNode;
            }
            cNode = cNode->next;
        }
        return head;
    }
};