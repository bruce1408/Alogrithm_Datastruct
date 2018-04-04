/*两个链表，然后相加，得到一个新的链表；
  我自己的这种方法不好，越做越复杂，网上的思路是对的，
  我这种思路有问题。*/


#include<iostream>
#include<cmath>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

void print_list(struct ListNode *head);

/*自己写的，最后没有写好，先反转，然后再变成n位数相加，最后把结果再倒序，非常麻烦*/
// class Solution
// {
	// public:
	// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	// {
		
		// int m1 = 0;
		// int m2 = 0;
		// int sumList = 0;
		// int wi = 0;
		// int temp ;
		// m1 = resultList(l1);
		// m2 = resultList(l2);
		// sumList = m1+m2;
		// temp = sumList;
		
		// cout<<sumList<<endl;
		// for(int i=0;sumList>0;++i)
		// {
			// sumList/=10;
			// wi = i;
		// }
		// cout<<wi<<endl;
		// for(int j=wi;j>=0;j--)
		// {
			
			// int val=0;
			// val = temp % 10;
			// temp = temp/10;
			// cout<<"val:"<<val<<endl;
		// }
	// }
	
	// //这个是链表得到一个n位数1->3->4 变成 431
	// int resultList(ListNode *head)
	// {	int m = 0;
		// int result = 0;
		// while(head)
		// {
			// result += (head->val)*pow(10,m);
			// m++;
			// head = head->next;
		// }
		// return result;
	// }
	
	
// };





int main()
{
	ListNode c1 {3,NULL};
	ListNode b1 {4,&c1};
	ListNode a1 {2,&b1};
	ListNode *head1 = a1;
	
	ListNode c2 {4,NULL};
	ListNode b2 {6,&c2};
	ListNode a2 {5,&b2};
	ListNode *head2 = &a2;

	ListNode *before = NULL;
	
	print_list(head1);
	print_list(head2);
	
	Solution s;
	before = s.addTwoNumbers(head1,head2);
	print_list(before);
	return 0;

}


void print_list(struct ListNode *head)
{
	while(head)
	{
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<"end"<<endl;
}



/*leetcode标准参考答案*/
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry=0;
        ListNode* res=new ListNode(0);
        ListNode* head = res;
        while (l1 && l2){
            res->next=new ListNode((l1->val+l2->val+carry)%10);
            carry = (l1->val+l2->val+carry)/10;
            l1=l1->next;
            l2=l2->next;
            res=res->next;
        }        
        while (l1){
            res->next=new ListNode((l1->val+carry)%10);
            carry = (l1->val+carry)/10;
            l1=l1->next;
            res=res->next;
        }        
        while (l2){
            res->next=new ListNode((l2->val+carry)%10);
            carry = (l2->val+carry)/10;
            l2=l2->next;
            res=res->next;
        }        
        if (carry>0){
            res->next = new ListNode(carry);
        }        
        return head->next;        
    }
};





















