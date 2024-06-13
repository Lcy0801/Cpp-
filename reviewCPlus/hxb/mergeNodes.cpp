#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeNodes(ListNode* head)
{
    ListNode *cNode = head;
    ListNode *newHead = nullptr;
    ListNode *lastNode = nullptr;
    bool flag = false;
    int sum = 0;
    while (cNode)
    {
        if(!flag && cNode->val)
        {
            sum = cNode->val;
            flag = true;
        }
        else if(flag && cNode->val)
        {
            sum += cNode->val;
        }
        else if(flag && !cNode->val)
        {
            flag = false;
            ListNode *newNode = new ListNode(sum);
            if(!newHead)
            {
                newHead = newNode;
            }
            else
            {
                lastNode->next = newNode;
            }
            lastNode = newNode;
            sum = 0;
        }
        cNode = cNode->next;
    }
    return newHead;
}

int main()
{
    ListNode *node1 = new ListNode(0);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(1);
    ListNode *node4 = new ListNode(0);
    ListNode *node5 = new ListNode(4);
    ListNode *node6 = new ListNode(5);
    ListNode *node7 = new ListNode(2);
    ListNode *node8 = new ListNode(0);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    ListNode *newnode = mergeNodes(node1);
    while (newnode)
    {
        cout << newnode->val<<endl;
        newnode = newnode->next;
    }
    system("pause");
    return 0;
}