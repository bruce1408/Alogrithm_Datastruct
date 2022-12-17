/* ---------------------------------------排序之 直接插入排序算法----------------------------*/
#include<iostream>
using namespace std;
struct sqlist
{
	int r[6];
	int length;
};

void print_array(sqlist *l);//函数声明

void swap(sqlist *l,int i,int j);

void InsertSort(sqlist *l)              // 直接插入排序(升序)代码一：
{
	int i,j,key;
	for (i=1;i<l->length;i++)
	{
		key = l->r[i];
		if(l->r[i]<l->r[i-1])
		{
			
			for (j=i-1;l->r[j]>key;j--) // 插入位置的判断。
			{
				l->r[j+1] = l->r[j];
			}
			
			l->r[j+1] = key; 
		}
	}
}


void insertSort_0(sqlist *l)        // 直接插入排序(升序)代码二：
{
    int i, j, key;
    for (i = 1; i < l->length; i++)
	{
        key = l->r[i];
        for (j = i - 1; j >= 0; j--)
		{
			
            if (l->r[j] > key) 
			{
                l->r[j + 1] = l->r[j];
            }
            else
                break;
        }
        l->r[j + 1] = key;
    }
}


void insertSort_1(sqlist *l)
{
	for(int i=1;i<l->length;i++)
	{
		int key = l->r[i];
		int j=i-1;
		while (j>=0 && l->r[j]>key)
		{
			l->r[j+1] = l->r[j];
			j--;
		}
		l->r[j+1] = key;
	}
}



int main()
{
	sqlist *l;
	// sqlist r[10] = {0,9,1,5,8,3,7,4,6,2};
	sqlist r[6] = {9,5,3,4,6,2};
	
	l = r;
	l->length = sizeof(l->r)/sizeof(l->r[0]);
	cout<<"排序之前的结果："<<endl;
	print_array(l);
	cout<<"直接插入排序算法的结果："<<endl;
	// InsertSort(l);
	insertSort_1(l);
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






















