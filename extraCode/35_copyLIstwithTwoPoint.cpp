// 画图分析
#include<iostream>
#include<map>
using namespace std;

//复杂链表，每个节点都有两个指针，一个是指向下一个节点的next，还有一个是指向任何节点的指针
struct RandomListNode
{
  int val;
  RandomListNode * next;
  RandomListNode * random;
  RandomListNode(int x):val(x),next(NULL),random(NULL) {}
};

// 方法1：res是复制后的链表的头结点，node遍历res，cur遍历原来的链表，一共需要设置三个指针。
// 再加一个 map 哈希表
RandomListNode * copyRandomList(RandomListNode *head)
{
  if(!head) return nullptr;
  RandomListNode * res = new RandomListNode(head->val);
  RandomListNode * node = res;
  RandomListNode * cur = head->next;
  map<RandomListNode*,RandomListNode*> temp;
  temp[head] = res; // 先把头结点装进去，cur指向的是下一个待复制节点
  while(cur) // 复制next链表的值
  {
    RandomListNode *tmp = new RandomListNode(cur->val);
    node->next =  tmp;
    temp[cur] = tmp;
    node = node->next;
    cur = cur->next;
  }
  node = res;
  cur = head;
  while(node)
  {
    node->random = temp[cur->random];
    node = node->next;
    cur = cur->next;
  }
  return res;
}
//方法2
RandomListNode*copyRandomList2(RandomListNode*head)
{
  if(!head) return nullptr;
  RandomListNode * cur = head;
  while(cur) // 每个链表后面复制一个链表和它相同
  {
    RandomListNode*node = new RandomListNode(cur->val);
    node->next = cur->next;
    cur->next = node;
    cur = node->next;
  }
  cur=head;
  while(cur) // 将原来的random所指的复制给新的链表的random
  {
    if(cur->random) cur->next->random = cur->random->next;
    cur = cur->next->next;
  }
  cur = head;
  RandomListNode *res = head->next;// 拆分后新链表的头结点；
  while(cur) // 拆除链表
  {
    RandomListNode*tmp = cur->next;
    cur->next = tmp->next;
    if(tmp->next) tmp->next = tmp->next->next;
    cur = cur->next;
  }
  return res;
}

// the function of print the linklist
void printCopyList(RandomListNode*node)
{
  while(node)
  {
    cout<<node->val<<" ";
    if(node->random)  cout<<node->random->val<<endl;
    else cout<<"null"<<endl;
    node = node->next;
  }
  cout<<endl;
}


int main()
{
  // create a complexlist
  RandomListNode *head = new RandomListNode(1);
  RandomListNode *head2 = new RandomListNode(2);
  RandomListNode *head3 = new RandomListNode(3);
  RandomListNode *head4 = new RandomListNode(4);
  RandomListNode *head5 = new RandomListNode(5);
  head->next = head2;
  head->random = head3;
  head2->next = head3;
  head2->random = head5;
  head3->next = head4;
  head4->next = head5;
  head4->random = head2;

  //test and print the result;
  RandomListNode* node = copyRandomList2(head);
  printCopyList(node);
  return 0;

}
