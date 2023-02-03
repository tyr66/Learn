#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
public:
    Node(int _key, int _value) : key(_key), value(_value), next(nullptr), prev(nullptr) {}
    Node() : key(-1), value(-1), next(nullptr), prev(nullptr) {}
    Node(int _key, int _value, Node *_next, Node *_prev) : key(_key), value(_value), next(_next), prev(_prev) {}

public:
    int key;
    int value;
    Node *next;
    Node *prev;
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        this->max_capacity = capacity;
        this->count = 0;
    }

    int get(int key)
    {
        if (ump.find(key) == ump.end() || ump[key] == nullptr)
            return -1;
        udpateNode(ump[key]);
        return ump[key]->value;
    }

    void put(int key, int value)
    {
        if (ump.find(key) != ump.end() && ump[key] != nullptr)
        {
            ump[key]->value = value;
            udpateNode(ump[key]);
            return;
        }

        //不存在
        if (count == max_capacity)
        {
            removeFirstNode();
        }

        Node *new_node = addNode(key, value);
        ump[key] = new_node;
    }

    ~LRUCache()
    {
    }

private:
    void udpateNode(Node *tar)
    {
        if (count == 1 || tail.prev == tar)
            return;

        Node *prev_node = tar->prev;
        Node *next_node = tar->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;

        Node *last_node = tail.prev;
        last_node->next = tar;
        tar->prev = last_node;
        tar->next = &tail;
        tail.prev = tar;
    }

    void removeFirstNode()
    {
        if (count == 0)
            return;

        if (count == 1)
        {
            ump[head.next->key] = nullptr;

            delete head.next;
        }
        else
        {
            Node *tar = head.next;
            Node *next_node = tar->next;
            ump[tar->key] = nullptr;
            head.next = next_node;
            next_node->prev = &head;
            delete tar;
        }

        count--;

        if (count == 0)
        {
            head.next = nullptr;
            tail.prev = nullptr;
        }
    }

    Node *addNode(int key, int value)
    {
        Node *new_node = new Node(key, value);

        if (count == 0)
        {
            head.next = tail.prev = new_node;
            new_node->next = &tail;
            new_node->prev = &head;
        }
        else
        {
            new_node->prev = tail.prev;
            tail.prev->next = new_node;
            new_node->next = &tail;
            tail.prev = new_node;
        }

        count++;

        return new_node;
    }

private:
    unordered_map<int, Node *> ump;
    Node head;
    Node tail;
    int max_capacity;
    int count;
};

int main()
{
    return 0;
}