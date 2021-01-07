#include <iostream>
#include <vector>
using namespace std;

/**
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，
 * 使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
*/

/**
 * 方法 1，使用三个指针来做
*/
void sortColors(vector<int> &num)
{
	int count0 = 0, count1 = 0, count2 = 0;
	for (auto i : num)
	{
		if (i == 0)
			count0++;
		else if (i == 1)
			count1++;
		else
			count2++;
	}
	int j = 0;
	while (j < count0)
		num[j++] = 0;

	while (j < count1 + count1)
		num[j++] = 1;

	while (j < count0 + count1 + count2)
		num[j++] = 2;
}

int main()
{
	vector<int> num = {0, 2, 1, 0, 1};
	sortColors(num);
	for (auto i : num)
		cout << i << " ";
}