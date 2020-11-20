/** 排序算法之简单选择排序
 **/

#include<iostream>
using namespace std;

struct sqlist
{
	int r[10];
	int length;
};

void swap(sqlist *l,int i,int j) //交换数组中的两个元素
{
	int temp = l->r[i];
	l->r[i] = l->r[j];
	l->r[j] = temp;
}



void SimpleSelectSort(sqlist *l)              // 简单选择排序(升序)代码：
{
	int i,j,min;
	for (i=1;i<l->length;i++)
	{
		min = i;
		for (j=i+1;j<=l->length;j++)
		{
			if(l->r[min]>l->r[j])
				min = j;
		}
		if (i != min)
			swap(l,i,min);
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
	
	
	cout<<"排序之前的结果："<<endl;
	
	print_array(l);
	cout<<"简单选择排序算法的结果："<<endl;
	SimpleSelectSort(l);
	print_array(l);
	
	return 0;
}



























