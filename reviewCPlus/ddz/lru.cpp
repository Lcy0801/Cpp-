#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int val;
    int key;
    Node *next;
    Node *prev;
    Node(int key, int x) : key(key), val(x), next(nullptr), prev(nullptr){};
};

class LRUCache
{
private:
    unordered_map<int, Node *> keyNodes;
    Node *head = nullptr;
    Node *tail = nullptr;
    int m_capacity;
    void moveToHead(Node *node)
    {
        if (node->prev)
        {
            node->prev->next = node->next;
            if (node->next)
            {
                node->next->prev = node->prev;
            }
            else
            {
                // 更新尾节点
                tail = node->prev;
            }
            // 更新头节点
            node->prev = nullptr;
            node->next = head;
            head->prev = node;
            head = node;
        }
        return;
    }

public:
    LRUCache(int capacity)
    {
        m_capacity = capacity;
        keyNodes.reserve(capacity);
    }

    int get(int key)
    {
        if (keyNodes.find(key) == keyNodes.end())
        {
            return -1;
        }
        Node *node = keyNodes.at(key);
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (keyNodes.find(key) == keyNodes.end())
        {
            // 删除最久未使用的节点
            if (keyNodes.size() == m_capacity)
            {
                keyNodes.erase(tail->key);
                if (tail->prev)
                {
                    tail->prev->next = nullptr;
                    Node *tmp = tail->prev;
                    delete tail;
                    tail = tmp;
                }
                else
                {
                    tail = nullptr;
                    head = nullptr;
                }
            }
            // 插入新的节点
            Node *node = new Node(key, value);
            // 更新头节点
            node->prev = nullptr;
            node->next = head;
            if(head)
            {
                head->prev = node;
            }
            head = node;
            // 更新尾节点
            if (tail == nullptr)
            {
                tail = node;
            }
            keyNodes.insert(make_pair(key, node));
        }
        else
        {
            Node *node = keyNodes.at(key);
            node->val = value;
            moveToHead(node);
        }
        return;
    }
};


int main()
{
    LRUCache lru(3);
    lru.put(1, 1); 
    lru.put(2, 2); 
    lru.put(3, 3); 
    lru.put(4, 4); 
    lru.get(4);    
    lru.get(3);    
    lru.get(2);    
    lru.get(1);    
    lru.put(5, 5); 
    lru.get(1);    
    lru.get(2);     
    lru.get(3);    
    lru.get(4);
    lru.get(5);
    system("pause");
    return 0;
}