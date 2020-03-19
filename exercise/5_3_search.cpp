/*-------------------------------search 专栏-------------------------- */


/*有序查找*/
//二分查找，折半查找
//前提条件是必须是有序的数组，如果是频繁要删除插入的序列，那么不建议用二分查找
#include<iostream>
#include<vector>
using namespace std;


int binary_search(int *a,int key,int n)
{
	int low,high,mid;
	low = 0;
	high = n;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(key<a[mid])
			high = mid-1;
		else if(key>a[mid])
			low = mid+1;
		else
			return mid;
	}
	return -1;//找不到
}

//插值查找
//对于表长较大，而且分布比较均匀，插值查找性能优于二分查找。
int insert_search(int *a,int key,int n)
{
	int low,high,mid;
	low = 0;
	high = n-1;//和二分不一样，下面要从high开始。
	while(low<=high)
	{
		mid = low+(high-low)*(key-a[low])/(a[high]-a[low]);//插值查找的关键点
		if(key<a[mid])
			high = mid-1;
		else if(key>a[mid])
			low = mid+1;
		else
			return mid;
	}
	return -1;//找不到
}

//斐波那契查找
//先判断目标序列的长度，在斐波那契数列属于哪个值的范围区间，比如长度为10，在斐波那契中小于13,13的下标是7，
//然后补全原数组的值，从n一直到F[k]-1
int fibo_search(int *a,int n,int key)
{
	int F[] = {0,1,1,2,3,5,8,13,21,34};
	int low,high,mid,i,k;
	low = 1;
	high = n-1;
	k = 0;
	while(high>F[k]-1)
	{
		k++;
	}
	
	for(int i=n;i<F[k]-1;i++)
		a[i]=a[high];
	
	while(low<=high)
	{
		mid = low+F[k-1]-1;
		if(key<a[mid])
		{
			high = mid-1;
			k-=1;
		}
		else if(key>a[mid])
		{
			low = mid+1;
			k-=2;
		}
		else
		{
			if(mid<=n-1)
				return mid;
			else
				return n-1;
		}
	}
	return -1;
}


//二叉排序树、二叉查找树
//构建一课二叉排序树的目的不是在于排序，而是提高查找和插入删除的速度。二叉排序树的非线性结构利于这种操作。

int main()
{
	//二分查找
	// int a[] = {2,3,5,7,9,12,14,24,36};
	// int n = sizeof(a)/sizeof(a[0]);
	// cout<<binary_search(a,23,9);
	//插值查找
	// int a[] = {2,3,5,7,9,12,14,24,36};
	// int n = sizeof(a)/sizeof(a[0]);
	// cout<<insert_search(a,24,n);
	//斐波那契查找
	// int a[] = {0,1,16,24,35,47,59,62,73,88,99};
	// int n = sizeof(a)/sizeof(a[0]);
	// cout<<fibo_search(a,n,99);
	
	return 0;
}

































