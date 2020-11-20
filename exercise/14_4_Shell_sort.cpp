/**
 * 排序之 直接插入排序算法
 * */
#include<iostream>
using namespace std;
struct sqlist
{
	int r[10];
	int length;
};

void print_array(sqlist *l);//函数声明
void swap(sqlist *l,int i,int j);

void ShellSort1(sqlist *l)              // 希尔排序(升序)代码一：
{
	int i,j,temp;
	int increment = l->length;
	
	do
	{
		increment = increment/3+1;
		for(i = increment;i<l->length;i++)
		{
			if(l->r[i]<l->r[i-increment])
			{
				temp = l->r[i];
				for(j=i-increment;j>=0&&temp<l->r[j];j-=increment)
					l->r[j+increment] = l->r[j];
				l->r[j+increment] = temp;
			}
				
		}
	}while(increment>1);
}





void ShellSort2(sqlist *l)          // 希尔排序(升序)for循环。代码二：
{
	int i,j,temp;
	int increment = l->length;
	
	for(increment=increment/3+1;increment>0;increment--)
	{
		
		for(i = increment;i<l->length;i++)
		{
			if(l->r[i]<l->r[i-increment])
			{
				temp = l->r[i];
				for(j=i-increment;j>=0&&temp<l->r[j];j-=increment)
					l->r[j+increment] = l->r[j];
				l->r[j+increment] = temp;
			}
				
		}
	}
}


void ShellSort3(sqlist *l)      // 希尔排序代码三：
{  
    int gap = l->length;  
	do
    // for(gap=gap/3+1; gap >0; gap--)  
    {  
		gap = gap/3+1;
        for(int i=0; i<gap; i++)  
        {  
            for(int j = i+gap; j<l->length; j=j+gap)  
            {  
                if(l->r[j]<l->r[j-gap])  
                {  
                    int temp = l->r[j];  
                    int k = j-gap;  
                    while(k>=0&&l->r[k]>temp)  
                    {  
                        l->r[k+gap] = l->r[k];  
                        k = k-gap;  
                    }  
                    l->r[k+gap] = temp;  
                }  
            }  
        }  
    }while(gap>1);  
}  





int main()
{
	sqlist *l;
	sqlist r[10] = {9,0,1,5,8,3,7,4,6,2};
	// sqlist r[9] = {592,401,874,141,348,72,911,887,820};
	// sqlist r[6] = {9,5,3,4,6,2};
	
	l = r;
	l->length = sizeof(l->r)/sizeof(l->r[0]);
	cout<<"排序之前的结果："<<endl;
	print_array(l);
	cout<<"希尔排序算法的结果："<<endl;
	ShellSort2(l);
	// shell_sort(l);
	
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






















