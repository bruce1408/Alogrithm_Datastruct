#include <iostream>
#include <vector>
using namespace std;

/**
 * 把链表拉伸，该链表有next，pre，child 三个指针，返回的是一个没有孩子节点的链表
*/
class Node
{
public:
    int val = NULL;
    Node *prev = NULL;
    Node *next = NULL;
    Node *child = NULL;
    Node() {}
    Node(int _val, Node *_prev, Node *_next, Node *_child)
    {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

/**
 * 方法 1
*/
Node *flatten1(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *p = head;
    while (p)
    {
        if (p->child == nullptr)
        {
            p = p->next;
            continue;
        }
        // case 1: has a child node
        Node *temp = p->child;
        while (temp->next)
            temp = temp->next;
        temp->next = p->next;
        // 链接两根线，next 和 pre
        if (p->next != nullptr)
            p->next->prev = temp;
        p->next = p->child;
        p->child->prev = p;
        p->child = nullptr;
    }
    return head;
}

/**
 * 方法 2
*/
Node *flatten2(Node *head)
{
    for (Node *h = head; h; h = h->next)
    {
        if (h->child)
        {
            Node *next = h->next;
            h->next = h->child;
            h->next->prev = h;
            h->child = NULL;
            Node *p = h->next;
            while (p->next)
                p = p->next;
            p->next = next;
            if (next)
                next->prev = p;
        }
    }
    return head;
}