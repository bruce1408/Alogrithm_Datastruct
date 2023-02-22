#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 根据输入来创建链表的两种方式
 * 第一种就是定义结构体是常规的，不带构造体的结构体，
 * 第二种就是定义结构体是升级的，含有构造体的结构体；
*/

/**
 * 第一种，不带有构造体的结构体来创建一个新的链表，基本和带构造体的类似
 * 不过在最后一个节点，要给末尾的链表指针赋值为空才可以；不然的话就有问题
 * 因为你结构体这部分并没有初始化。
*/
// struct linklist
// {
//     int val;
//     linklist *next;
// };

// int main()
// {
//     int k = 4;
//     linklist *head = new linklist;
//     linklist *cur = head;
//     while (k)
//     {
//         linklist *temp = new linklist;
//         temp->val = k;
//         cur->next = temp;
//         cur = temp;
//         k--;
//     }
//     head = head->next;
//     cur->next = nullptr;
//     while (head)
//     {
//         cout << head->val << " ";
//         head = head->next;
//     }
//     return 0;
// }

/**
 * 第二种，带有构造体的结构体来创建一个新的链表
 * 首先创建一个新的头节点，然后后面穿件的不断的指向这个节点，这个节点也向后遍历即可，
 * 最后返回的是这个头结点的下一个节点，而不是当前的节点；
*/
struct linklist
{
    int val;
    linklist *next;
    linklist(int x) : val(x), next(NULL) {}
};

int main()
{
    int k = 4;
    linklist *head = new linklist(0);
    linklist *cur = head;
    while (k)
    {
        linklist *temp = new linklist(k);
        cur->next = temp;
        cur = temp;
        k--;
    }
    head = head->next;
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}