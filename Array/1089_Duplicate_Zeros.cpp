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
 * 方法 1，从后向前需要两个指针，left，left从最后的len-2到0的范围内遍历数组，
 * 如果这个值是0的话，那么这个时候再设置一个指针是临时指针right指向数组的最后一个元素，只要这个指针的下标
 * 是比当前的left下标大的话，那么就是把数组的前一个数赋值给数组的后一个数字即可。，然后每次right--
 * 但是时间复杂度较高是O(M*N),M和N分别是两个数组的长度
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
 * 利用两个指针i和j，同时从数组的开头算起，然后把原来数组的数字赋给这个新的数组，接着
 * 进行判断，如果这个数字是0的话，那么 判断包含0的变量 numOfZeros 要自加一次，同时指针i
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
 * 方法 3，这个方法非常巧妙！时间复杂度为O(n)，空间复杂度是O(1):
 * 思路就是先找到数组中的出现0的个数zerosCount，然后设置两个指针i从数组的最后1位向前遍历，
 * j从数组的长度+zerosCount处
 * 开始遍历，如果数组当前位置i的数字是非0的，那么那么再接着判断j是不是大于数组长度，
 * 如果不是，则把i的数值赋值给j对应的下标数字；
 * 如果当前位置i的数字是0，那么还是判断j是不是大于数组长度，如果小于数组长度，那么我们要把0复制两次才可以，做法就是让i的值赋值给j
 * 的值，然后再让j--，再把i的值赋值给j减后的值，这样，0就赋值了两次，然后i，j继续向前遍历即可！
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
    duplicateZeros2(a);
    for (auto i : a)
    {
        cout << i << " ";
    }
}