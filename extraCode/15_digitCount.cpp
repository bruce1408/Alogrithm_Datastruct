#include<iostream>
using namespace std;

/**
 * 题目：统计二进制中的1的个数，例如 9，二进制是1001，1的个数是 2；
 * 方法 位运算
 * 思路：
 * 对 2 的商累加，然后该数对赋值为对 2 整除的数；例子1
 * 利用位移也可以做，比如每次该数右移以为，然后和 1 相与，结果不是0，那么就自加一次；
 * 位移出了上面的数，也可以是1左移，左移一位之后也可以起到同样的效果；
 * */
int digitCount1(int n)
{
	if(n<1) return 0; // 只允许大于1的数字，否则返回0，此方法没有考虑n是负数的情况
	int count = 0;
	while(n)
	{
		count+=n%2;
		n = n/2;
	}
	return count;
}

//方法2 利用位运算,遇到有符号数会陷入死循环,没有特别对负数做出判断
int digitCount2(int n)
{

	int count = 0;
	while(n)
	{
		if(n&1)
			count++;
		n = n>>1;
	}
	return count;
}

//方法3 升级版，数字 1 左移然后在和 n 做与运算；把数字 1 左移即可；
int digitCount3(int n)
{
	int count = 0;
	unsigned int i=1; // 无符号数1左移
	while(i)
	{
		if(n&i)
			count++;
		i = i<<1;
	}
	return count;
}

// 方法4 把这个数字转换成无符号数，然后在右移即可
int digitCount4(int n)
{
	unsigned int x = n;
	int s = 0;
	while(x)
	{
		s+=(x&1);
		x>>=1;
	}
	return s;
}

int main()
{
	// unsigned int n = 9;
	int x = -9;
	//无符号32位二进制数最后移位会到0。
	// while(n)
	// {
		// n =n<<1;
		// cout<<n<<endl;
	// }
	cout<<digitCount4(x)<<endl;
}












