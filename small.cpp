/*判断回文链表的题目
  这里的题目是一个类里面的一个方法：
  先求出链表的长度，得到链表的中心点，从中心点*/
// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>          // std::priority_queue
// using namespace std;
// struct ListNode
// {
// int val;
// ListNode *next;

// };

// void print_list(struct ListNode *head);

// string a1 = "c1";
// string a2 = "c2";
// string a3 = "c1";
// if(a1 == a2)
// cout<<"c1==c2"<<endl;
// else if(a1 ==a3)
// cout<<"a1==a3"<<endl;
// if (a1<a2)
// cout<<"a1<a2"<<endl;

// int n = 5;
// n = n/2-((n % 2) ^ 1);
// cout<<n<<endl;

// class Solution
// {
// public:
// //求链表的长度，并且返回链表的中心点算法；
// bool palindrom(ListNode *head)
// {
// int n=0;
// ListNode *pos = head;
// while(pos != NULL)
// {
// n++;
// pos = pos -> next;
// }
// if(n == 0 || n == 1)
// return true;
// n = n / 2 - ((n % 2) ^ 1);//找出中心点；
// pos = head;//
// for(int i = 0 ; i < n ; i++){
// pos = pos -> next;//中心点位置
// }
// // if(pos ==NULL||pos->next==NULL)
// // return pos;
// //这里开始对后半段链表反转
// ListNode* rear = NULL;//让第一个为空
// ListNode* p = pos;
// ListNode* before = pos;
// while(p)
// {
// before = p;
// p = p->next;//工作指针
// before->next = rear;
// rear = before;//rear 是反转后的头结点

// }
// // return rear;

// //比较前半段链表和反转的后半段链表；
// for(int i = 0;i<n;++i)
// {
// if(head->val != rear->val)
// {
// cout<<"不是回文链表"<<endl;
// return false;
// }
// else
// {
// head = head->next;
// rear = rear->next;
// }
// return true;

// }
// }

// };

// int main()
// {
// // vector<int> l1;
// //自己造一个回文链表

// ListNode e = {1,NULL};
// ListNode d = {2,&e};
// ListNode c = {3,&d};
// ListNode b = {2,&c};
// ListNode a = {1,&b};
// ListNode *head = &a;
// ListNode *f = head;
// ListNode *half = head;
// ListNode *reve = head;
// bool ifase = false;
// Solution s;
// ifase = s.palindrom(f);
// cout<<"中心点后半部分反转之后的链表是：";
// // print_list(half);
// cout<<ifase<<endl;

// // reve = s.ReverseList(half);

// // print_list(reve);

// return 0;
// }

// ////打印部分：
// void print_list(struct ListNode *head)
// {
// while(head)
// {
// cout<<head->val<<"->";
// head = head->next;
// }
// cout<<"end"<<endl;
// }

/*两个方法是一样的，只不过第一个方法是用一个函数写在里面，
  这个函数是在一个类里面用了三个函数来写。*/
// #include<iostream>
// #include<string>

// using namespace std;
// struct ListNode
// {
// int val;
// ListNode *next;

// };

// void print_list(struct ListNode *head);

// class Solution
// {
// public:
// //求链表的长度，并且返回链表的中心点算法；
// ListNode *palindrom(ListNode *head)
// {
// int n=0;
// ListNode *pos = head;
// while(pos != NULL)
// {
// n++;
// pos = pos -> next;
// }
// if(n == 0 || n == 1)
// return head;
// n = n / 2 - ((n % 2) ^ 1);
// cout<<n<<endl;
// pos = head;
// for(int i = 0 ; i < n ; i++){
// pos = pos -> next;
// }
// return pos;

// }
// //反转链表的算法：
// ListNode* ReverseList(ListNode* pHead){
// if (pHead == NULL || pHead->next == NULL){
// return pHead;
// }

// ListNode* rear = NULL;
// ListNode* p = pHead;
// ListNode* before = pHead;
// while(p){

// before = p;
// p = p->next;//工作指针
// before->next = rear;
// rear = before;

// }
// return rear;
// }

// bool isPalindrom(ListNode *head,ListNode *rear)
// {

// for(int i = 0;i<2;++i)
// {
// if(head->val != rear->val)
// {
// cout<<"不是回文链表"<<endl;
// return false;
// }
// else
// {
// head = head->next;
// rear = rear->next;
// }
// return true;

// }
// }

// private:
// static int length;

// };

// int main()
// {
// // vector<int> l1;
// //自己造一个回文链表

// ListNode e = {1,NULL};
// ListNode d = {2,&e};
// ListNode c = {3,&d};
// ListNode b = {2,&c};
// ListNode a = {1,&b};
// ListNode *head = &a;
// ListNode *f = head;
// ListNode *half = head;
// ListNode *reve ;
// bool ifase = false;

// Solution s;
// half = s.palindrom(f);
// cout<<"中心点后半部分链表是：";
// print_list(half);
// reve = s.ReverseList(half);

// cout<<"中心点后半部分反转之后的链表是：";
// print_list(reve);

// ifase = s.isPalindrom(head,reve);

// if(ifase)
// cout<<"是回文链表"<<endl;
// else
// cout<<"不是回文链表"<<endl;
// // // print_list(head);
// // print_list(reve);

// return 0;
// }

// //打印部分：
// void print_list(struct ListNode *head)
// {
// while(head)
// {
// cout<<head->val<<"->";
// head = head->next;
// }
// cout<<"end"<<endl;
// }

// #include<iostream>
// #include<vector>
// using namespace std;

// struct ListNode
// {
// int val;
// ListNode *next;

// };

// void print_list(struct ListNode *head);

// class Solution
// {
// public:
// ListNode *deleteDuplicates(ListNode *head)
// {
// ListNode *p = head;
// while(p&&p->next)
// {
// if(p->next->val == p->val)
// {
// p->next = p->next->next;
// }
// else
// {
// p = p->next;
// }
// }
// return head;
// }

// };

// int main()
// {

// ListNode e = {3,NULL};
// ListNode d = {3,&e};
// ListNode c = {2,&d};
// ListNode b = {1,&c};
// ListNode a = {1,&b};
// ListNode *head = &a;
// ListNode *before = head;

// print_list(head);

// Solution s;
// print_list(s.deleteDuplicates(before));

// return 0;

// }

// void print_list(struct ListNode *head)
// {
// while(head)
// {
// cout<<head->val<<"->";
// head = head->next;
// }
// cout<<"end"<<endl;
// }

// #include<iostream>
// using namespace std;
// int main()
// {
// int temp = 2004;
// int wi = 3;
// for(int j=wi;j>=0;j--)
// {

// int val=0;
// val = temp % 10;
// temp = temp/10;
// cout<<"val:"<<val<<endl;

// }

// return 0;
// }

// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// using namespace std;

// void Msort(string a,int low,int high);
// int partition(string a,int low,int high);
// void swap(string a,int low,int high);

// void Msort(string a,int low,int high)
// {
// int pivot;//定义一个枢轴值的位置；
// while (low<high)
// {
// pivot = partition(a,low,high);//得到枢轴值的位置
// Msort(a,low,pivot-1);
// low = pivot+1;
// }
// }

// int partition(string a,int low,int high)
// {
// int povikey;
// //省略了三数取中法
// povikey = a[low];
// while(low<high)
// {
// while(low<high && a[high]>=povikey)
// high--;
// swap(a,low,high);
// while(low<high && a[low]<=povikey)
// low++;
// swap(a,low,high);

// }
// return low;
// }

// void swap(string a,int low,int high)
// {
// int temp = a[low];
// a[low] = a[high];
// a[high] = temp;
// }

// int main()
// {
// string a("anagram");
// string b("nagaram");
// sort(a.begin(),a.end());
// sort(b.begin(),b.end());
// if(a==b)
// cout<<"yes:"<<endl;
// cout<<a<<endl;
// int la=0,lb=0;
// cout<<a.length()<<endl;
// cout<<a[2]<<endl;
// la = sizeof(a);
// cout<<"a的长度是："<<la<<endl;
// cout<<"a的长度是："<<a.size()<<endl;

// Msort(a,0,4);
// for(int i;i<5;i++)
// cout<<a[i]<<" ";
// cout<<endl;

// char str[] = "we are poor students";//这是一个字符串
// cout<<str<<endl;//输出的是：we are poor students。这也是字符串的优点，可以整个输出。

// //指针访问每个字符并输出。
// char *p = str;
// while (*p != '\0')
// {
// cout << *p;
// p++;
// }

// cout<<endl;
// string str1 = "we are poor students";
// for (string::iterator p1 = str1.begin(); p1 !=str1.end(); p1++)
// {
// cout << *p1 ;
// }

// return 0;
// }

// #include<iostream>
// #include<string>
// using namespace std;

// int main()
// {
// 	string a = "5";
// 	int b = stoi(a);
// 	cout<<b<<endl;
// 	cout<<a<<endl;
// 	return 0;
// }

// 找出某个数字的位置索引
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main()
// {
//     vector<int> v = { 10, 10, 30, 30, 30, 100, 10, 300, 300, 70, 70, 80 };

//     // Declaring an iterator to store the
//     // return value of std::equal_range
//     pair<vector<int>::iterator, vector<int>::iterator> ip;

//     // Sorting the vector v
//     sort(v.begin(), v.end());
//     // v becomes 10 10 10 30 30 30 70 70 80 100 300 300

//     // Using std::equal_range and comparing the elements
//     // with 30
//     ip = equal_range(v.begin(), v.begin() + 12, 30);

//     // Displaying the subrange bounds
//     cout << "30 is present in the sorted vector from index "
// 	<< (ip.first - v.begin()) << " till "
// 	<< (ip.second - v.begin());

//     return 0;
// }

// int main()
// {
// 	cout << "the int min is: " << INT_MIN << endl;
// 	cout << "the long min is: " << LONG_MIN << endl;
// 	cout << "the int max is: " << INT_MAX << endl;
// 	cout << INT_MAX + 3 << endl; // 这么写会溢出
// 	cout << 3 + (INT_MAX - 3) / 2 << endl;
	// vector<vector<int>> res = {
	// 	{1, 1, 0},
	// 	{1, 0, 1},
	// 	{0, 0, 0}};
	// for (auto &row : res)
	// 	reverse(row.begin(), row.end()); // 每行翻转
	// for (auto &row : res)
	// {
	// 	for (int &num : row)
	// 		num ^= 1;
	// }

	// for (auto &i : res)
	// {
	// 	for (auto j : i)
	// 		cout << j << " ";
	// 	cout << endl;
	// }

	// vector<vector<int>> uu(res.size());
	// for (auto &i : uu)
	// {
	// 	for (auto j : i)
	// 		cout << j << " ";
	// 	cout << endl;
	// }

	// vector<int> nums = {1, 5, 3, 4, 5, 6, 7};
	// int minVal = INT_MAX;
	// int maxVal = INT_MIN;

	// for (int i = 1; i < nums.size(); ++i)
	// 	if (nums[i] < nums[i - 1]) // 当前位置比前面位置的数字还要小，可能是最小值
	// 		minVal = min(nums[i], minVal);

	// for (int i = nums.size() - 2; i >= 0; --i)
	// 	if (nums[i] > nums[i + 1]) //当前位置数字比后面数字还要大，那么可能是最大值；这样的思路很容易写位置的初始化
	// 		maxVal = max(nums[i], maxVal);

	// cout << minVal << " " << maxVal << endl;
	// vector<string> res;
	// for (int i = 0; i < 4; i++)
	// {
	// 	res.push_back(string(1, i + 'a'));
	// }
	// for (auto i : res)
	// {
	// 	cout << i << endl;
	// }
// }


/**
 * 优先队列 部分学习
 * 普通的队列是先进先出，元素在队列尾部追加，在头部删除，
 * 优先队列的特点就是最大的元素总是位于队首的位置，所以出队的时候，是输出当前队列的最大元素，类似给队列中的元素
 * 进行了从大到小的排序过程；
*/
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main ()
{
  priority_queue<int> mypq;

  mypq.emplace(3);
  mypq.emplace(4);
  mypq.emplace(2);
  mypq.emplace(1);

  cout << "mypq contains:";
  while (!mypq.empty())
  {
     cout << ' ' << mypq.top();
     mypq.pop(); // 删除顶部元素；
  }
  cout << '\n';

  return 0;
}