#include <iostream>
#include <vector>
using namespace std;

/**
 * 75 颜色分类
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，
 * 使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
*/

/**
 * 方法 1，使用三个变量依次记录0，1，2的个数，然后保存在新的数组里面
*/
void sortColors(vector<int> &num)
{
	vector<int> count(3);
	for (auto i : num)
		count[i]++;
	for (int i = 0, t = 0; i < count.size(); i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			num[t++] = i;
		}
	}
}

/**
 * 方法 2，使用两个指针，分别表示0和1之间的界限，和1和2之间的界限
 * 扫面一遍然后空间是常数级别要求
*/
void sortColors2(vector<int> &res)
{
	// i维护的是数字1的情况，j表示数字0，都是从左往右，k是从右往左，维护的是数字2的情况
	for (int i = 0, j = 0, k = res.size() - 1; i <= k;)
	{
		if (res[i] == 0) // 如果指针i当前数字是1，那么就交换i和j的，同时向右移动一位即可
			swap(res[i++], res[j++]);
		else if (res[i] == 2)
			swap(res[i], res[k--]); // 因为k个位置的数字不一定是1，所以i不要自加，k减小1位
		else
			i++;
	}
}

/**
 * 方法 3，并非此题目的解答，而是测试，针对排好序的数组，
 * 按照前一个数小于后一个数，然后后一个数大于前一个数的类型进行重新排列即可
 * 这里使用的是一个映射关系A(i)
*/
void sortColors3(vector<int> &res)
{
	int n = res.size();
#define A(i) res[(1 + 2 * i) % (n | 1)]
	// int mid = res[n/2];
	sort(res.begin(), res.end());
	int mid = res[n / 2];
	for (int i = 0, j = 0, k = n - 1; i <= k;)
	{
		if (A(i) > mid) 
			swap(A(i++), A(j++));
		else if (A(i) < mid)
			swap(A(i), A(k--));
		else
			i++;
	}
}
int main()
{
	// vector<int> num = {0, 2, 1, 0, 1};
	// sortColors2(num);
	// for (auto i : num)
	// 	cout << i << " ";

	// 做实验测试
	vector<int> res = {1, 2, 1, 4, 5, 1, 7};
	sortColors3(res);
	for (auto i : res)
		cout << i << " ";
}