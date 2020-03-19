#include <iostream>
using namespace std;

/**
 * 32位编译器
 * char ：1个字节
 * char*（即指针变量）: 4个字节
 * 32位的寻址空间是2^32, 即32个bit，也就是4个字节。同理64位编译器）
 * short int : 2个字节
 * int：  4个字节
 * unsigned int : 4个字节
 * float:  4个字节
 * double:   8个字节
 * long:   4个字节
 * long long:  8个字节
 * unsigned long:  4个字节
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
 */

/**
 * 
 * 有符号数与无符号数字相加的话，要先转换为无符号数，然后执行加法
 * 操作，有符号数转换的方法是：
 * 有符号数+无符号数的模，无符号数占4个字节32位，所以模是2^32，-8 + 2^32
*/
int main()
{
	int x = 9;
	int y = -8;
	unsigned int a = y; // y + 2^32
	cout << a << endl;
	cout << a + x << endl;
	cout << sizeof(unsigned int) << endl;
	unsigned int b = 4200000000; // b - 2^32
	int c = b;
	cout << c << endl;
}