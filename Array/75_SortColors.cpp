#include <iostream>
#include <vector>
using namespace std;

/**
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
*/
void sortColors2(vector<int> &num)
{
	int i = 0, j = num.size() - 1; // 两个指针，分别表示0-1界限和1-2界限
	for (int k = 0; k <= j;)
	{
		if (num[k] == 0)
			swap(num[k++], num[i++]);
		else if (num[k] == 2)
			swap(num[k], num[j--]);
		else
			k++;
	}
}

int main()
{
	vector<int> num = {0, 2, 1, 0, 1};
	sortColors2(num);
	for (auto i : num)
		cout << i << " ";
}