#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){};
    ListNode(int x) : val(x){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

class MyLinkedList
{
private:
    ListNode *head;

public:
    MyLinkedList()
    {
        head = nullptr;
    }
    MyLinkedList(ListNode *head) : head(head){};
    int get(int index)
    {
        if (!head)
            return -1;
        int val = -1;
        ListNode *cur = head;
        while (cur)
        {
            if (index > 0)
            {
                cur = cur->next;
                index--;
            }
            else
                break;
        }
        if (index == 0 && cur)
            val = cur->val;
        return val;
    }

    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        return;
    }

    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        ListNode *cur = head;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        return;
    }
    // 要注意添加元素在头节点的情况
    void addAtIndex(int index, int val)
    {
        if (index < 0)
            return;
        ListNode *cur = head;
        ListNode *last = nullptr;
        while (cur)
        {
            if (index)
            {
                last = cur;
                cur = cur->next;
                index--;
            }
            else
                break;
        }
        if (index == 0)
        {
            ListNode *newNode = new ListNode(val);
            newNode->next = cur;
            if (last)
            {
                last->next = newNode;
            }
            else
            {
                head = newNode;
            }
        }
        return;
    }
    // 要注意删除元素在头节点的情况
    void deleteAtIndex(int index)
    {
        if (!head || index < 0)
            return;
        ListNode *cur = head;
        ListNode *last = nullptr;
        while (cur)
        {
            if (index)
            {
                last = cur;
                cur = cur->next;
                index--;
            }
            else
                break;
        }
        if (index == 0 && cur)
        {
            if (last)
            {
                // 删除非首节点
                last->next = cur->next;
            }
            else
            {
                // 删除首节点
                head = head->next;
            }
            // 释放删除节点的内存
            delete cur;
        }
        return;
    }
    void printList()
    {
        if (!head)
            return;
        ListNode *cur = head;
        while (cur)
        {
            cout << cur->val << "\t";
            cur = cur->next;
        }
        cout << endl;
        return;
    }
    // 反转链表 注意更新头节点指针
    void reverseList()
    {
        if (!head)
            return;
        ListNode *cur = head;
        ListNode *last = nullptr;
        while (cur)
        {
            ListNode *temp = cur->next;
            cur->next = last;
            last = cur;
            cur = temp;
        }
        head = last;
        return;
    }
    // 两两交换链表中相邻的节点
    void swapPairs()
    {
        if(!head || !head->next)
            return;
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *before = nullptr;
        head = head->next;
        while (true)
        {
            first->next = second->next;
            second->next = first;
            if(before)
                before->next = second;
            // 移动到下一个节点对
            before = first;
            first = first->next;
            if(first && first->next)
                second = first->next;
            else
                break;
        }
    }
    // 删除倒数第n个节点
    void removeNthFromEnd(int n)
    {
        if(!head || n<=0)
            return;
        ListNode *fast = head;
        ListNode *slow = head;
        int i;
        for (i = 0; i < n;i++)
        {
            fast = fast->next;
            if(!fast)
                break;
        }
        if(!fast && i ==n-1)
        {
            // 要删除的节点为头节点
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return;
        }else if(fast)
        {
            // 要删除的节点存在，并且不为头节点
            while (fast->next)
            {
                fast=fast->next;
                slow = slow->next;
            }
            ListNode * temp = slow->next;
            slow->next = slow->next->next;
            delete temp;
        }
        return;
    }
    ~MyLinkedList()
    {
        if (!head)
            return;
        ListNode *cur = head;
        ListNode *next = nullptr;
        while (cur)
        {
            next = cur->next;
            delete cur;
            cur = next;
        }
        return;
    }
    // 获取两个相交链表的起始相交节点
    static ListNode * getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode * heada=headA;
        ListNode *headb = headB;
        while(heada && headb)
        {
            heada = heada->next;
            headb = headb->next;
        }
        int na = 0, nb = 0;
        while (heada)
        {
            na++;
            heada = heada->next;
        }
        while (headb)
        {
            nb++;
            headb = headb->next;
        }
        heada =headA;
        headb = headB;
        if(na)
        {
            for (int i = 0; i < na;i++)
                heada = heada->next;
        }
        else
        {
            for (int i = 0; i < nb;i++)
                headb = headb->next;
        }
        while (heada!=headb)
        {
            heada = heada->next;
            headb = headb->next;
        }
        return heada;
    }
};

int main()
{
    MyLinkedList l;
    l.addAtHead(7);
    l.addAtHead(2);
    l.addAtHead(1);
    l.addAtIndex(3, 0);
    l.printList();
    l.deleteAtIndex(2);
    l.printList();
    l.addAtHead(6);
    l.addAtHead(4);
    l.printList();
    cout << l.get(4) << endl;
    system("pause");
    return 0;
}