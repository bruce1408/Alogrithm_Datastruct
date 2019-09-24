#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Given a fixed length array arr of integers, 
 * duplicate each occurrence of zero, 
 * shifting the remaining elements to the right.
 * Note that elements beyond the length of the original array are not written.
 * Do the above modifications to the input array in place, 
 * do not return anything from your function.
 * 
 * Input: [1,0,2,3,0,4,5,0]
 * Output: null
 * Explanation: After calling your function, 
 * the input array is modified to: [1,0,0,2,3,0,0,4]
 * 给定一个数组，然后有0的话，把0重复往后移动一位 *
 * *
 * 这个题目是遇到0则多复制1位，也可以扩展到遇到其他数字后向复制1位。
*/

/**
 * 方法 1，从后向前需要两个指针，每次更新之后就累加一次新的数组中偶数的和，
 * 但是时间复杂度较高是O(M*N),M和N分别是两个数组的长度，方法超时了
*/

void duplicateZeros(vector<int> &arr)
{
    int len = arr.size();
    int left = len - 2, right = len - 1;
    for (int i = left; i >= 0; i--)
    {
        if (arr[i] == 0)
        {
            right = len - 1;
            while (right > i)
            {
                arr[right] = arr[right - 1];
                right--;
            }
        }
    }
}

/**
 * 方法 2，利用一个新的数组来做，空间复杂度是O(n)，时间复杂度是O(n)
 * 利用两个指针，同时从数组的开头算起，然后把当前的数字赋给这个数组，接着
 * 进行判断，如果这个数字是0的话，那么 numOfZeros要自加一次，同时一个指针
 * 也要自增一次，如果说numOfZeros是大于0的数字，说明出现了0，则，arr[i]=0
 * 同时numOfZeros 自减1，如果说这个数字既不是0，也不是有0出现，则指针j自增
 * 一位即可。
 * 这个利用了新的数组
*/
void duplicateZeros1(vector<int> &arr)
{
    vector<int> temp = arr;
    int i = 0, j = 0, numZeros = 0;
    int len = arr.size();
    while (i < len && j < len)
    {
        arr[i] = temp[j];
        if (arr[i] == 0)
        {
            numZeros++;
            j++;
        }
        else if (numZeros > 0)
        {
            arr[i] = 0;
            numZeros--;
        }
        else
        {
            j++;
        }
        i++;
    }
}

/**
 * 方法 3，时间复杂度为O(n)，空间复杂度是O(1):
 * 思路就是先找到数组中的0的个数，然后两个指针从数组长度+0的个数开始遍历，
 * 一个是i从原始数组最后一位开始，一个是新的加了0的个数之后的数组，j从最后
 * 一位开始向前遍历，如果i的位置该数字是0的话，那么判断j是不是小于数组长度
 * 然后把i的位置的数字赋值给j的位置，然后j在自减一位，在把i的值赋给当前的
 * j的位置，相当于是遇到数字0就把0复制两次即可。
 * 如果该i的位置的数字不是数字0，那么直接把i的数字赋值给数字j即可，j和i同时--
 *  
*/
void duplicateZeros2(vector<int> &arr)
{
    int countZeros = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            countZeros += 1;
    }
    int oldLen = arr.size();
    int newLen = arr.size() + countZeros;
    for (int i = oldLen - 1, j = newLen - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i] != 0)
        {
            if (j < arr.size())
                arr[j] = arr[i];
        }
        else
        {
            if (j < arr.size())
                arr[j] = arr[i];
            j--;
            if (j < arr.size())
                arr[j] = arr[i];
        }
    }
}

int main()
{
    vector<int> a = {1, 0, 2, 3, 0, 4, 5, 0};
    duplicateZeros1(a);
    for (auto i : a)
    {
        cout << i << " ";
    }
}