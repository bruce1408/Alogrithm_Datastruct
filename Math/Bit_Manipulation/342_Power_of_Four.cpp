#include <iostream>
#include <vector>
using namespace std;

/**
 * Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 * 
 * Example 1:
 * Input: 16
 * Output: true
*/

bool isPowerOfFour(int num)
{
    while (num && num % 4 == 0)
    {
        num /= 4;
    }
    return num == 1;
}

int main()
{
    int k = 4;
    while (k)
    {
        int x;
        cout<<"请输入一个数："<<endl;
        cin >> x;
        cout << "the x is: " << x << "the power is: " << isPowerOfFour(x) << endl;
        k--;
    }
}