#include<iostream>
#include<vector>
using namespace std;

// 这一道题目就是说定义节点结构，有孩子节点，返回的是一个没有孩子节点的链表
class Node 
{
    public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;
    Node() {}
    Node(int _val, Node* _prev, Node* _next, Node* _child) 
    {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};


Node * flatten(Node*head)
{
    if(head==nullptr) return nullptr;
    Node *p = head;
    while(p)
    {
        if(p->child==nullptr)
        {
            p = p->next;
            continue;
        }
        // case 1: has a child node
        Node* temp = p->child;
        while(temp->next) temp = temp->next;
        temp->next = p->next;
        // 链接两根线，next 和 pre
        if(p->next!=nullptr) p->next->prev = temp;
        p->next = p->child; 
        p->child->prev = p;
        p->child = nullptr;
    }


}
int main()
{
    return 0;
}