// #include<iostream>
// #include<vector>
// using namespace std;

// struct listNode
// {
	// int val;
	// listNode *next;	
// };

// void print_list(struct listNode *head);
/*算法一：判断是否是回文链表，就是遍历链表，然后把值放到
  容器中去，在容器中判断是否是回文数
  容器中，设置两个数值，i和j，一个从0开始，一个从最后一个位置开始比较，分别自增
  和自减1。然后通过下标来判断是不是相同
  算法的时间复杂度是O(n),但是空间复杂度也是O(n)*/
// int main()
// {
	// vector<int> l1;
	// //自己造一个回文链表
	// listNode e = {1,NULL};
	// listNode d = {2,&e};
	// listNode c = {3,&d};
	// listNode b = {2,&c};
	// listNode a = {1,&b};
	// listNode *head = &a;
	// listNode *p = head;
	
	// print_list(head);
	
	// while(p)
	// {
		// l1.push_back(p->val);
		// p = p->next;
	// }
	// for(auto i:l1)
		// cout<<i<<" ";
	// cout<<endl;
	
	// //判断是不是回文数的算法！这个算法牛逼，for循环可以这么玩！
	// for(int i=0,j=l1.size()-1;i<j;++i,--j)
	// {
		// if(l1[i]!=l1[j])
			// cout<<"不是回文数：";		
	// }
	// cout<<"是回文链表！"<<endl;
	
	
	// //反转容器
	// // for(vector<int>::reverse_iterator it = l1.rbegin();it!=l1.rend();++it)
		// // cout<<*it<<" ";
	
	// return 0;
// }

// void print_list(struct listNode *head)
// {
	// while(head)
	// {
		// cout<<head->val<<"->";
		// head = head->next;
	// }
	// cout<<"end"<<endl;
// }



/*算法二：回文链表，找到中间链表然后反转。*/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
		{
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }//while
        slow = slow->next;
        // 翻转
        ListNode* q = ReverseList(slow);
        // 判断是否是回文串
        ListNode* p = head;
        while(p && q){
            if(p->val != q->val){
                return false;
            }//if
            p = p->next;
            q = q->next;
        }//while
        return true;
    }
private:
    // 翻转
    ListNode* ReverseList(ListNode* head){
        if(head == nullptr){
            return head;
        }//if
        // 头结点
        ListNode* dummy = new ListNode(-1);
        ListNode* p = head;
        ListNode* nextNode = p->next;
        while(p){
            nextNode = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = nextNode;
        }//while
        return dummy->next;
    }
};

int main(){
    Solution s;
	
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

    bool result = s.isPalindrome(head);
    if(result){
        cout<<"是回文串"<<endl;
    }//if
    else{
        cout<<"不是回文串"<<endl;
    }//else
    return 0;
}




































