#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode * _next):val(x),next(_next){}
};

class MyLinkedList 
{
    public:

    MyLinkedList():head_(nullptr),tail_(nullptr),size_(0){}
    ~MyLinkedList()
    {
        ListNode *p = head_;
        while(p)
        {
            ListNode *cur = p;
            p = p->next;
            delete cur;
        }
        head_ = nullptr;
        tail_ = nullptr;
    }
    int get(int index)
    {
        if(index<0 || index>size_) return -1;
        auto p = head_;
        while(index--)
        {
            p = p->next;
        }
        return p->val;
    }
    // 头部插入节点
    void addAtHead(int val) 
    {
        head_ = new ListNode(val,head_);
        if(size_++==0) tail_ = head_; // 如果加之前是0的话，只有一个节点，尾部节点和头指向一处
    }

    void addAtTail(int val) 
    {
        auto node = new ListNode(val);
        if(size_++==0) 
        {
            head_ = tail_ = node;
        }
        else
        {
            tail_->next = node;
            tail_ = node;
        }
    }
    void addAtIndex(int index, int val) 
    {
        if(index<0||index>size_) return ;
        if(index==0) return addAtHead(val);
        if(index==size_) return addAtTail(val);
        ListNode dummy(0, head_);  //非常经典的dummy节点，所以我们要加一个dummy节点，在指向删除的前一个节点。栈上创建
        ListNode * cur = &dummy;
        while(index--)
        {
            cur = cur->next;
        }
        cur->next = new ListNode(val,cur->next);
        ++size_;
    }
    void deleteAtIndex(int index) 
    {
        if(index>size_||index<0) return;
        ListNode dummy(0,head_);
        ListNode *p = &dummy;
        for(int i=0;i<index;i++)
        {
            p = p->next;
        }
        ListNode * node_to_delete = p->next;
        p->next = p->next->next;
        if(index==0) head_ = p->next; // 维护删除后的那个head和tail
        if(index==size_-1) tail_ = p;
        delete node_to_delete;
        size_--; 
    }
    private:
    ListNode * head_;
    ListNode * tail_;
    int size_;
};