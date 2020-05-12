/* --------------------------------排序之 归并排序算法----------------------------*/
#include <iostream>
using namespace std;
struct sqlist
{
	int r[9];
	int length;
};

void print_array(sqlist *l); //函数声明
void swap(sqlist *l, int i, int j);

/**
 * 归并排序算法
 */

void MergeSort(sqlist *l);
void Msort(int old_arr[], int modi_arr[], int s, int t);
void Merge(int res_arr2[], int modi_arr[], int i, int m, int n);

void MergeSort(sqlist *l)
{
	Msort(l->r, l->r, 0, l->length - 1);
}

void Msort(int old_arr[], int modi_arr[], int i, int t) // 真正的算法实体；
{
	int m;
	int res_arr2[10];
	if (i == t) // 递归终止的条件
		modi_arr[i] = old_arr[i];
	else
	{
		m = (i + t) / 2;
		Msort(old_arr, res_arr2, i, m);
		Msort(old_arr, res_arr2, m + 1, t);
		Merge(res_arr2, modi_arr, i, m, t);
	}
}

// 合并有序序列，代码更加简洁，逻辑明了！
void Merge(int res_arr2[], int modi_arr[], int i, int m, int n)
{

	int k = i;
	int j = m + 1;
	while (i <= m && j <= n)
	{
		if (res_arr2[i] < res_arr2[j])

			modi_arr[k++] = res_arr2[i++];
		else
			modi_arr[k++] = res_arr2[j++];
	}

	while (i <= m)
		modi_arr[k++] = res_arr2[i++];

	while (j <= n)
		modi_arr[k++] = res_arr2[j++];
}

int main()
{
	sqlist *l;
	// sqlist r[10] = {9,0,1,5,8,3,7,4,6,2};
	sqlist r[9] = {50, 10, 90, 30, 70, 40, 80, 60, 20};

	l = r;
	l->length = sizeof(l->r) / sizeof(l->r[0]);
	cout << "排序之前的结果：" << endl;
	print_array(l);
	MergeSort(l);
	cout << "归并排序之后的结果是：" << endl;
	print_array(l);

	return 0;
}

void print_array(sqlist *l) //打印显示代码
{
	// n = l->length;
	for (int i = 0; i < l->length; i++)
		cout << l->r[i] << " ";
	cout << endl;
}

void swap(sqlist *l, int i, int j)
{
	int temp = l->r[i];
	l->r[i] = l->r[j];
	l->r[j] = temp;
}
