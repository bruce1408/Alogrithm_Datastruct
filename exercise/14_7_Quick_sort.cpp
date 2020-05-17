#include <iostream>
using namespace std;

struct sqlist
{
	int r[9];
	int length;
};

void print_array(sqlist *l);
void swap(sqlist *l, int i, int j);

int partition(sqlist *l, int low, int high);
void QuickSort(sqlist *l);
void Qsort1(sqlist *l, int low, int high);

// void Qsort(sqlist *l,int low,int high)
// {
// int pivot;
// if(low<high)
// {
// pivot = partition(l,low,high);// 返回枢轴值所在的位置
// cout<<"the pivot is: "<<l->r[pivot]<<"; " ;
// cout<<"the position of pivot is: "<<pivot<<endl;
// Qsort(l,low,pivot-1);
// Qsort(l,pivot+1,high);

// }
// }

/* ------------------------ 上面的Qsort部分的代码进行优化！！--------------------*/

// void Qsort1(sqlist *l, int low, int high)
// {
// 	int pivot;
// 	while (low < high) //取消二次迭代的部分，换成while
// 	{
// 		pivot = partition(l, low, high); // 返回枢轴值所在的位置
// 		cout << "the pivot is: " << l->r[pivot] << "; ";
// 		cout << "the position of pivot is: " << pivot << endl;
// 		Qsort1(l, low, pivot - 1);
// 		low = pivot + 1; //精妙的部分！
// 	}
// }

// void QuickSort(sqlist *l)
// {
// 	Qsort1(l, 0, l->length - 1);
// }

// int partition(sqlist *l, int low, int high)
// {
// 	//如何确定枢轴数值，这里不再是直接去low，而是通过三数取中的办法
// 	int pivotkey;
// 	int m = low + (high - low) / 2;
// 	if (l->r[low] > l->r[high])
// 		swap(l, low, high);
// 	if (l->r[m] > l->r[high])
// 		swap(l, m, high);
// 	if (l->r[low] < l->r[m])
// 		swap(l, low, m);

// 	pivotkey = l->r[low];

// 	//接下来是让枢轴值两侧的数字变换，左侧的小于它，右侧的大于它。

// 	while (low < high)
// 	{
// 		while (low < high && l->r[high] >= pivotkey)
// 			high--;
// 		swap(l, low, high);

// 		while (low < high && l->r[low] <= pivotkey)
// 			low++;
// 		swap(l, low, high);
// 	}

// 	return low;
// }

// int main()
// {
// 	sqlist *l;
// 	// sqlist r[9] = {50,10,90,30,70,40,80,60,20};
// 	sqlist r[9] = {9,1,5,8,3,7,4,6,2};
// 	l = r;
// 	l->length = sizeof(l->r)/sizeof(l->r[0]);
// 	cout<<"排序之前的结果："<<endl;
// 	print_array(l);
// 	QuickSort(l);
// 	cout<<"快速排序之后的结果是："<<endl;
// 	print_array(l);
// 	return 0;
// }

// void print_array(sqlist *l) //打印显示代码
// {

// 	for (int i = 0; i < l->length; i++)
// 		cout << l->r[i] << " ";
// 	cout << endl;
// }

// void swap(sqlist *l, int i, int j)
// {
// 	int temp = l->r[i];
// 	l->r[i] = l->r[j];
// 	l->r[j] = temp;
// }

void merge(vector<int> &nums, int length, int left, int middle, int right)
{

}
void mergeSort(vector<int> &nums, int length, int left, int right)
{
	if (left + 1 < right)
	{
		int middle = (left + right) / 2;
		mergeSort(nums, length, left, middle);
		mergeSort(nums, length, middle + 1, right);
		merge(num, left, length, middle, right);
	}
	else
	{
		return;
	}
}

int main()
{
	vector<int> res = {5, 4, 6, 7, 1, 2, 9};
	mergeSort(res, 0, 7);
	for (auto i : res)
	{
		cout << i < " ";
	}
}
