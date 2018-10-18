/*判断是否是有链表环*/
#include<iostream>
#include<cstring>
using namespace std;


struct linkNode
{
	char c;
	linkNode *next;
		
};


int main()
{
	
	linkNode *p = head;
	linkNode *head = &a;
	linkNode a = {'a',&b};
	linkNode b = {'b',&c};
	linkNode c = {'c',&d};
	linkNode d = {'d',&e};
	linkNode e = {'e',&f};
	linkNode f = {'f',&d};
	return 0;
}


/*判断是否链表环*/
bool hasCycle(struct linkNode *head)
{
	linkNode *fast = head;
	linkNode *slow = head;
	
	while(fast!=NULL&&slow!=NULL&&fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast==slow)
			return true;
		
	}
	return false;//如果到最后没有跳出，那么就是说链表没有环
}







/*求链表环的第一个结点*/
class Solution {
public:
 ListNode *detectCycle(ListNode *head) {
		
		if(head==NULL||head->next==NULL)
			return NULL;
		
        ListNode* fast = head;
        ListNode* slow = head;
	
        // do
        // {
            // if(fast != NULL)
                // fast = fast->next;
            // else
                // return NULL;
            // if(fast != NULL)
                // fast = fast->next;
            // else
                // return NULL;
            // slow = slow->next;
        // }while(fast != slow);
		
		
		//这种方法有错误
		while(fast->next->next&&fast->next)
		{
			
			fast = fast->next->next;
			slow = slow->next;
			if(fast==slow)
				break;
		}
		if(fast->next == NULL || fast->next->next == NULL)
            return NULL;
		
        fast = head;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};


/*C++寻找环的第一个入口交点的第二种方法*/

// ListNode *detectCycle(ListNode *head) {
    // if (head == NULL || head->next == NULL)
        // return NULL;
    
    // ListNode *slow  = head;
    // ListNode *fast  = head;
    // ListNode *entry = head;
    
    // while (fast->next && fast->next->next) {
        // slow = slow->next;
        // fast = fast->next->next;
        // if (slow == fast) {                      // there is a cycle
            // while(slow != entry) {               // found the entry location
                // slow  = slow->next;
                // entry = entry->next;
            // }
            // return entry;
        // }
    // }
    // return NULL;                                 // there has no cycle
// }






























