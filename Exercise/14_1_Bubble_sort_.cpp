/**
 * 排序之冒泡排序算法
 * */
#include<iostream>
using namespace std;

struct sqlist
{
	int r[10];
	int length;
};

void swap(sqlist *l,int i,int j)
{
	int temp = l->r[i];
	l->r[i] = l->r[j];
	l->r[j] = temp;
}

void BubbleSort1(sqlist *l)              // 冒泡排序(升序)代码一：
{
	int i,j;
	for (i=1;i<l->length;i++)
	{
		for (j=i+1;j<=l->length;j++)
		{
			if(l->r[i]>l->r[j])
				swap(l,i,j);
		}
	}
}

void BubbleSort2(sqlist *l)              // 冒泡排序(升序)代码二 升级版：
{
	int i,j;
	for (i=1;i<l->length;i++)
	{
		for (j=l->length-1;j>=i;j--)
		{
			if(l->r[j]>l->r[j+1])
				swap(l,j,j+1);
		}
	}
}


void BubbleSort3(sqlist *l)              // 冒泡排序(升序)代码三 升级版：
{
	int i,j;
	bool flag = true;                   // 增加了一个标记为，如果已经是排好序了，那么后面就不需要再循环i的值了。节省次数
	for (i=1;i<=l->length && flag;i++)
	{
		flag = false;
		for (j=l->length-1;j>=i;j--)
		{
			if(l->r[j]>l->r[j+1])
				swap(l,j,j+1);
				flag = true;
		}
	}
}

void BubbleSort(sqlist *l)              // 冒泡排序反序：
{
	int i,j;
	for (i=1;i<l->length;i++)
	{
		for (j=l->length-1;j>=i;j--)
		{
			if(l->r[j]>l->r[j-1])
				swap(l,j,j-1);
		}
	}
}

void print_array(sqlist *l) //打印显示代码
{
	// n = l->length;
	for (int i = 0;i<l->length;i++)
		cout<<l->r[i]<<" ";
	cout<<endl;
}



int main()
{
	sqlist *l;
	sqlist r[10] = {0,9,1,5,8,3,7,4,6,2};
	
	l = r;
	l->length = sizeof(l->r)/sizeof(l->r[0]);
	
	// l->r[0]=8;
	// cout<<l->r[0]<<endl;
	cout<<"排序之前的结果："<<endl;
	// print_array(l);
	// swap(l,1,2);
	print_array(l);
	// BubbleSort1(l);
	// cout<<"冒泡排序算法1的结果："<<endl;
	// print_array(l);
	cout<<"冒泡排序算法3的结果："<<endl;
	BubbleSort3(l);
	print_array(l);
	
	return 0;
}



























