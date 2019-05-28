#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

/**
 * 题目：打印出n位数的从1到最大数，例如n=3，打印1，2，3，...999
 * 方法 利用字符串来做
 * 思路：
 * 看似是没有问题，直接for循环，但是会出现溢出的问题，所以最好的就是利用字符串来做
*/
//method 1
// void print_maxNum(int n)
// {
	// if(n<1)
		// cout<<0;
	// long long x=0;
	// for(int i=0;i<n;i++)
		// x += 9*pow(10,i);
	// for(long long j=1;j<=x;j++)
		// cout<<j<<" ";
// }

//方法2 search in network
void Print(vector<char>number, int n)
{
    int i = 0;
    for (; i<n; i++)
        if (number[i] != '0')
            break;
    if (i == n)
        return;
    for (; i<n; i++)
        cout<<number[i];
    cout<<" ";
}

void PrintRecursively(vector<char>number, int n, int index)
{
    if (index == n)
    {
        Print(number, n);
        return;
    }
    for (int i = 0; i<10; i++)
    {
        number[index] = i + '0';
        PrintRecursively(number, n, index + 1);
    }
}

void PrintToMaxOfNDigits(int n)
{
    if (n <= 0) return;
    vector<char> number(n, '0');
    PrintRecursively(number, n, 0);
}

//method 3
void PrintNumber(vector<char>number)
{
    bool isBeginning0 = true;
    int nLength = number.size();
    for (int i = 0; i < nLength; ++i)
    {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;

        if (!isBeginning0)
        {
            cout<<number[i]<<" ";
        }
    }
    cout<<endl;
}

bool Increment(vector<char>number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = number.size();
    for (int i = nLength - 1; i >= 0; i--)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum++;
        if (nSum >= 10)
        {
            if (i == 0)
                isOverflow = true;
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

void Print1ToMaxOfNDigits_1(int n)
{
    if (n <= 0)
        return;

    vector<char>number(n,'0');
    while (!Increment(number))
    {
        PrintNumber(number);
    }
}

int main()
{
	int a ;
    cout<<"请输入打印的位数 n: ";
	cin>>a;
	// 方法1
	// print_maxNum(a);
	// cout<<to_string(aa)<<endl;
	// 方法2：
	PrintToMaxOfNDigits(a);
	// method 3
	// Print1ToMaxOfNDigits_1(a);

}
