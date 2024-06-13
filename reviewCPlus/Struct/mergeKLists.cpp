#include <iostream>
#include <vector>
#include <memory>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = nullptr;
        ListNode *last = nullptr;
        ListNode *residual = nullptr;
        while (true)
        {
            int minV;
            int index = -1;
            int nullNum = 0;
            for (int i = 0; i < lists.size(); i++)
            {
                ListNode *cNode = lists[i];
                if (!cNode)
                {
                    nullNum++;
                    continue;
                }
                if (index == -1)
                {
                    minV = cNode->val;
                    index = i;
                }
                else if (minV > cNode->val)
                {
                    minV = cNode->val;
                    index = i;
                }
            }
            ListNode *minNode = lists[index];
            if (!head)
            {
                head = minNode;
            }
            else
            {
                last->next = minNode;
            }
            last = minNode;
            if (nullNum == (lists.size() - 1))
            {
                residual = lists[index]->next;
                break;
            }
            lists[index] = lists[index]->next;
        }
        while (residual)
        {
            last->next = residual;
            last = residual;
            residual = residual->next;
        }
        return head;
    }
};
int main()
{
    ListNode node1(1);
    ListNode node2(4);
    ListNode node3(5);
    node1.next = &node2;
    node2.next = &node3;
    ListNode node4(1);
    ListNode node5(3);
    ListNode node6(4);
    node4.next = &node5;
    node5.next = &node6;
    ListNode node7(2);
    ListNode node8(6);
    node7.next = &node8;
    vector<ListNode *> lists;
    lists.push_back(&node1);
    lists.push_back(&node4);
    lists.push_back(&node7);
    ListNode *head = Solution().mergeKLists(lists);
    while (head)
    {
        cout << head->val << "\t";
        head = head->next;
    }
    system("pause");
    return 0;
}