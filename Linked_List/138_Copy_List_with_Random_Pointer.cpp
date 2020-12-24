#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

/**
 * 138_copy list random pointer
 * 给定一个链表，它有三个属性，分别是val ，next ，还有random 三部分，现在需要深拷贝这个链表
 * 也就是说深度拷贝这个值，不是把地址给赋值，而是重新new一个新的链表
*/

/**
 * 方法 1，使用的是哈希表来保存这个链表的val值，然后再次遍历这个链表，来一个穿针引线的作用，
 * 把他的 next 和 random 都串起来即可！
*/
Node *copyRandomList(Node *head)
{
    if (!head)
        return nullptr;
    Node *res = new Node(head->val);
    Node *node = res, *cur = head->next;
    unordered_map<Node *, Node *> newList;
    newList[head] = res;
    while (cur)
    {
        Node *temp = new Node(cur->val);
        node->next = temp;
        newList[cur] = temp;
        node = node->next;
        cur = cur->next;
    }
    // 复制之后，node重新指回新节点的开头，cur指回原来节点的头结点，开始穿针引线
    node = res;
    cur = head;
    while (cur)
    {
        node->random = newList[cur->random];
        node = node->next;
        cur = cur->next;
    }
    return res;
}

/**
 * 方法 2，不用哈希来做，每个节点后面跟一个“小弟”
 * 然后原来是a的next是b，a的随机指针指向别的节点
 *      a---------->b
 *      a---->a'--->b
 * 然后复制之后再复制random指针即可
 * 最后把原来的节点拆除，恢复原链表，小弟链表的值我们使用新的链表跟在后面即可
*/
Node *copyRandomList(Node *head)
{
    // 复制一个小弟
    for (auto p = head; p; p = p->next->next)
    {
        Node *q = new Node(p->val);
        q->next = p->next;
        p->next = q;
    }

    // 赋值random指针
    Node *cur = head;
    while (cur)
    {
        if (cur->random)
            cur->next->random = cur->random->next;
        cur = cur->next->next;
    }

    // 拆分两个链表需要一个头结点
    Node *dummy = new Node(-1);
    cur = dummy;
    for (auto p = head; p; p = p->next)
    {
        auto q = p->next;
        cur->next = q;
        cur = cur->next;
        p->next = q->next;
    }
    return dummy->next;
}
