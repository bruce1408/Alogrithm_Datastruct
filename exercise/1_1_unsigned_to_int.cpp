#include <iostream>
using namespace std;

/**
 * 
 * 32位编译器
 * char ：1个字节
 * char*（即指针变量）: 4个字节（32位的寻址空间是2^32, 
 * 即32个bit，也就是4个字节。同理64位编译器）
 * short int : 2个字节
 * int：  4个字节
 * unsigned int : 4个字节
 * float:  4个字节
 * double:   8个字节
 * long:   4个字节
 * long long:  8个字节
 * unsigned long:  4个字节
 * 
 * 
 * 64位编译器
 * char ：1个字节
 * char*(即指针变量): 8个字节
 * short int : 2个字节
 * int：  4个字节
 * unsigned int : 4个字节
 * float:  4个字节
 * double:   8个字节
 * long:   8个字节
 * long long:  8个字节
 * unsigned long:  8个字节
 * 
 * 
 * 无符号数与有符号数之间的转换
 * 1，无符号数转换有符号数，(无符号数-无符号数所占的位数)
 * 无符号数转为有符号数的转换方法是:假设无符号数是N，
 * 无符号数的数据基本类型所占的位数是B位，则有符号数的表示是：
 * N - 2^B
 * 32位编译器无符号整型占4个字节，所以表示范围是2^32
 * 转换为有符号的数字是 N-2^32, N 是无符号数字，
 * 
 * 2，有符号数字转换无符号数字的情况
 * 有符号数+无符号数的所占位数
 * 
*/
int main()
{
	int x = 9;
	int y = -8;
	unsigned int a = y;
	cout << a << endl;
	cout << a + x << endl;
	cout << sizeof(a) << endl;
}