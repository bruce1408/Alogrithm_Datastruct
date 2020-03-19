#include <iostream>
#include <cmath>
// #include<>
using namespace std;


返回数组中值为value的元素下标
int findInArr(int *arr, int len, bool *diff, int value) {
	for (int i = 0; i < len; ++i) {
		if (diff[i] == true && arr[i] == value)
			return i;
	}

	return -1;
}

////返回数组中最大元素下标
int findMaxInArr(int *arr, int len, bool *diff) {
	int result = -1;

	int maxValue = INT_MIN;

	for (int i = 0; i < len; ++i) {
		if (diff[i] == false)
			continue;

		if (arr[i] >= maxValue) {
			result = i;
			maxValue = arr[i];
		}
	}

	return result;
}

int nswap(char* src, char* dst) {
	int s = atoi(src);
	int d = atoi(dst);
	
	int n = 0;

	//计算数字的位数
	int temp = s;
	while (temp != 0) {
		temp /= 10;
		++n;
	}

	bool *diff = new bool[n];
	int *sArr = new int[n];
	int *dArr = new int[n];

	for (int i = n - 1; i >= 0; --i) {
		sArr[i] = s % 10;
		s /= 10;
		dArr[i] = d % 10;
		d /= 10;

		diff[i] = (sArr[i] == dArr[i]) ? false : true;
	}

	int result = 0;

	for (int i = 0; i < n; ++i) {
		if (diff[i] == false)
			continue; 

		int sIndex = findInArr(sArr, n, diff, dArr[i]);
		if (sIndex != -1) { //找到相同的数
			diff[i] = false;
			sArr[sIndex] = sArr[i];
			if (sIndex != i) {
				++result;
			}
		}
	}

	// //取两个数组中的最大值
	// while (1) {
		// int maxDIndex = findMaxInArr(dArr, n, diff);
		// if (maxDIndex == -1)
			// break;

		// int maxSIndex = findMaxInArr(sArr, n, diff);

		// result += abs(dArr[maxDIndex] - sArr[maxSIndex]) + (maxDIndex == maxSIndex ? 0:1);
		// sArr[maxSIndex] = sArr[maxDIndex];
		// diff[maxDIndex] = false;
	// }

	// return result;
// }


// int main() 
// {
	// int result = nswap("12345", "23451");
	// printf("%d \n", result);
	// return 0;
// }