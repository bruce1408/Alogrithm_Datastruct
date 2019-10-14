#include <iostream>
#include <vector>
using namespace std;

/**
 * Given an array A of integers, return true if and only if we can partition the array into 
 * three non-empty parts with equal sums.
 * Formally, we can partition the array if we can find indexes i+1 < j with
 * (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... 
 * + A[A.length - 1])
 * 
 * Example 1:
 * Input: [0,2,1,-6,6,-7,9,1,2,0,1]
 * Output: true
 * Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
 * 
 * 给定一个数组,然后如果这个数组可以分成三部分,每部分元素之和相加相等的话,那么就返回True,否则返回的是False
*/

/**
 * 方法 1,先算这个数组的累加和,然后看是不是可以被3整除,被3整除后的数字记录为部分和sumNum,
 * 如果不可以,那么就返回false,然后再看这个数字,设置一个用来记录有几个部分和的变量,
 * 如果部分和相加等于sumNum,那么这个变量归零,同时记录的次数加1即可.
 * 最后判断部分和的个数是不是等于3?
*/
bool canThreePartsEqualSum(vector<int>& A)
{
    int sumNum = 0;
    for(size_t i=0;i<A.size();i++)
    {
        sumNum+=A[i];
    }
    if(sumNum%3!=0) return false;
    int eachSum = sumNum/3, partSum = 0, countNum = 0;
    for(size_t i=0;i<A.size();i++)
    {
        partSum+=A[i];
        if(partSum==eachSum)
        {
            partSum=0;
            countNum+=1;
        }        
    } 
    return (countNum==3);
}

int main()
{
    vector<int>res = {0,2,1,-6,6,-7,9,1,2,0,1};
    cout<<canThreePartsEqualSum(res)<<endl;
}