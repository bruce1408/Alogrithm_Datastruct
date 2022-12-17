/* --------------------------------排序之 堆排序算法----------------------------*/
#include<iostream>
using namespace std;
struct sqlist
{
	int r[9];
	int length;
};

void print_array(sqlist *l);//函数声明
void swap(sqlist *l,int i,int j);



//最大堆构建过程：
HeapAdjust(sqlist *l,int s,int m)
{
	int temp,j;
	temp = l->r[s];
	for(j=2*s+1;j<=m;j=j*2+1)
	{
		if(j<m&&l->r[j]<l->r[j+1])
			++j;
		if(temp>=l->r[j])
			break;
		l->r[s] = l->r[j];
		s = j;
	}
	l->r[s]=temp;
}



/*堆排序(升序)代码一：两次循环，一次是构成最大堆，第二次循环是最大根节点与末尾交换
  并再次调整为最大堆*/ 
  
void HeapSort(sqlist *l)              
{
	int i;
	
	for(i = l->length/2-1;i>=0;i--)// 构建最大堆
		HeapAdjust(l,i,l->length);
	cout<<"最大堆是："<<endl;
	print_array(l);
	
	cout<<"堆排序算法之后的结果是："<<endl;
	for(i=l->length-1;i>0;i--)
	{
		swap(l,0,i);
		HeapAdjust(l,0,i-1);
	}
}




int main()
{
	sqlist *l;
	// sqlist r[10] = {9,0,1,5,8,3,7,4,6,2};
	sqlist r[9] = {50,10,90,30,70,40,80,60,20};
	// sqlist r[6] = {9,5,3,4,6,2};
	
	l = r;
	l->length = sizeof(l->r)/sizeof(l->r[0]);
	cout<<"排序之前的结果："<<endl;
	print_array(l);
	HeapSort(l);
	print_array(l);
	
	return 0;
}


void print_array(sqlist *l)                 //打印显示代码
{
	// n = l->length;
	for (int i = 0;i<l->length;i++)
		cout<<l->r[i]<<" ";
	cout<<endl;
}

void swap(sqlist *l,int i,int j)
{
	int temp = l->r[i];
	l->r[i] = l->r[j];
	l->r[j] = temp;
}






















