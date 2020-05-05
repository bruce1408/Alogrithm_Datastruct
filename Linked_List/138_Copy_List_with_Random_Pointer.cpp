#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;

/**
 * 给定一个链表，它有三个属性，分别是val ，next ，还有random 三部分，现在需要深拷贝这个链表
 * 也就是说深度拷贝这个值，不是把地址给赋值，而是重新new一个新的链表
*/

/**
 * 方法 1，使用的是哈希表来保存这个链表的val值，然后再次遍历这个链表，来一个穿针引线的作用，
 * 把他的next 和 random 都串起来即可！
*/
Node* copyRandomList(Node* head) 
{
    if(!head) return nullptr;
    Node* res = new Node(head->val, NULL, NULL);
    Node* node = res, *cur = head->next;
    unordered_map<Node*, Node*>newList;
    newList[head] = res;
    while(cur)
    {
        Node *temp = new Node(cur->val, NULL, NULL);
        node->next = temp;
        newList[cur] = temp;
        node = node->next;
        cur = cur->next;
    }
    // 复制之后，node重新指回新节点的开头，cur指回原来节点的头结点，开始穿针引线
    node = res;cur = head;
    while(cur)
    {
        node->random = m[cur->random];
        node = node->next;
        cur = cur->next;
    }
    return res;
}

