/*349 求两个容器的交集，思路是想把两个容器用快速排序方法进行排序
  然后对排好序的容器进行遍历，如果1的值小于2的值，1自增，否则2自增，如果1和2相同，
  那么判断res容器是否是空或者是否和上次放的数值相同？满足条件的值放入res容器之中
  关键字：快速排序，遍历放值，不允许重复数字。*/
#include<iostream>
#include<vector>

using namespace std;
void print_vec(vector<int> num);
void swap(vector<int> &num,int low,int high);
int partition(vector<int> &num,int low,int high);
void Quicksort(vector<int> &num,int low,int high);


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
        vector<int> res;
        int i = 0, j = 0;
        // sort(nums1.begin(), nums1.end());//这里没有用algorithm算法，是自己手写的快速排序
        // sort(nums2.begin(), nums2.end());
		Quicksort(nums1,0,nums1.size()-1);
		Quicksort(nums2,0,nums2.size()-1);
        while (i < nums1.size() && j < nums2.size()) 
		{
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] > nums2[j]) ++j;
            else 
			{//这里一定要注意，就是判断里面的条件，如果是后判断空的话是错度。
                if (res.empty() || res.back() != nums1[i]) // 先后顺序一定要理清楚！
				{
                    res.push_back(nums1[i]);
                }
                ++i; ++j;
            }
        }
        return res;
    }
	
};


void Quicksort(vector<int> &a,int low,int high)
{
	int pivot;
	while(low<high)
	{
		pivot = partition(a,low,high);
		Quicksort(a,low,pivot-1);
		low = pivot+1;
	}
}


int partition(vector<int> &a,int low,int high)
{
	int pivotkey;
	//这里是三个数字取中来选枢轴值
	int m = low + (high-low)/2;
	if(a[low]>a[high])
		swap(a,low,high);
	if(a[m]>a[high])
		swap(a,m,high);
	if(a[low]<a[m])
		swap(a,low,m);
	
	pivotkey = a[low];
	//接下来是在枢轴值让左侧的小于它，右侧的大于他；
	while(low<high)
	{
		while(low<high && a[high]>=pivotkey)
			high--;
		swap(a,low,high);
		
		
		while(low<high && a[low]<=pivotkey)
			low++;
		swap(a,low,high);	
	}
	return low;
}



int main()
{
	int l1 = 4;
	int l2 = 2;
	int i=0,j=0;
	vector<int> num1 = {1,2,2,1};
	vector<int> num2 = {2,2};
	cout<<"排序之前的数组："<<endl;
	print_vec(num1);
	print_vec(num2);
		
	Solution s;
	cout<<"交集是："<<endl;
	print_vec(s.intersection(num1,num2));
	return 0;
}



void swap(vector<int> &a,int low,int high)
{
	
	int temp = a[low];
	a[low] = a[high];
	a[high] = temp;
}


void print_vec(vector<int> num)
{
	
	for(auto i:num)
		cout<<i<<" ";
	cout<<endl;
}









