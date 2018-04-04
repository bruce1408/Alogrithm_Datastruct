/*147 对链表进行插入排序，两轮遍历，一轮是遍历所有的元素，一轮是遍历已经排序
  的部分。思路2 是正确解答，思路一是一种尝试。*/
#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
/*147使用插入排序对其进行链表排序，第一种方法是将其转化成数组，然后数组排序*/
void print_list(ListNode *l);

int list_length(ListNode *l)//求链表长度
{
	int count=0;
	while(l)
	{
		count++;
		l = l->next;
	}
	return count;
}

//链表转化成数组
int *list_to_array(ListNode* l)
{
	int lenth = list_length(l);
	int *arrlist = new int[lenth];
	cout<<lenth<<endl;
	int i=0;
	
	while(l)
	{
		arrlist[i++] = l->val;
		// cout<<l->val<<endl;
		l = l->next;
	}
	
	return arrlist;
	
	// for(int i=0;i<lenth;i++)
		// cout<<arrlist[i]<<" ";
	// cout<<endl;
}

//插入排序
void InsertSort(int *arr)
{
	int i,j,key;
	for(i=1;i<7;i++)
	{
		key = arr[i];
		if(arr[i-1]>arr[i])
		{
			for(j=i-1;arr[j]>key;j--)
			{
				arr[j+1]=arr[j];
			}
			arr[j+1] = key;
		}
	}
	
}



/*----------------- 第二种排序方法是插入排序的链表版本 --------------------*/

ListNode* insertionSortList(ListNode* head)
{
	ListNode* sortHead = new ListNode(-1);
	while(head)
	{
		ListNode* cur= sortHead;
		ListNode* temp = head->next;
		//如果是cur第一次是空或者前面小于后面的，那么依次遍历
		while(cur->next != NULL && cur->next->val<head->val)
		{
			cur = cur->next;  // 满足条件，依次向后移动元素。
		}
		head->next = cur->next;
		cur->next = head;
		head = temp;
	}
	
	return sortHead->next;
	
}


int main()
{
	ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(2);
    ListNode* node7 = new ListNode(1);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
	print_list(head);
	
	
	ListNode *p;
	p = insertionSortList(head);
	print_list(p);
	
	return 0;
	
}


void print_list(ListNode *l)
{
	while(l)
	{
		cout<<l->val<<"->";
		l = l->next;
	}
	cout<<"end"<<endl;	
}

