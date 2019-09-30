#include <iostream>
#include <vector>
using namespace std;
/**
 * 两个人有糖果，放在数组A，B中，每个数组中的元素是bars的值，现在需要交换两个人的元素，然后
 * 使得最后两人的总的bars之和相同
 * 
 * Example 1:
 * Input: A = [1,1], B = [2,2]
 * Output: [1,2]
 * Example 2:
 * 
 * Input: A = [1,2], B = [2,3]
 * Output: [1,2]
 * 
 * Input: A = [1,2,5], B = [2,4]
 * Output: [5,4]
*/

/**
 * 方法 1是求出总的a和b数组的和，然后除2，得到每一个的和，然后遍历交换,代码写的跟屎一样，不说了，
 * 在leetcode 上报错，runtime error，可能是哪里出现了越界
*/

int sumVector(vector<int> partVector)
{
    int sum = 0;
    for (auto i : partVector)
    {
        sum += i;
    }
    return sum;
}

vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
{
    int totalSum = 0, aSum = 0;
    vector<int> res;
    for (int i = 0; i < A.size(); i++)
    {
        totalSum += A[i];
    }
    for (int i = 0; i < B.size(); i++)
    {
        totalSum += B[i];
    }
    int partSum = totalSum / 2, index = 0;
    while (aSum < partSum || index < A.size())
    {
        aSum += A[index++];
    }
    res.push_back(A[index - 1]);
    aSum -= A[index - 1];
    cout << aSum << " : " << endl;
    int i = 0, temp = A[index - 1], rightSum = aSum;
    vector<int> btemp(B);
    while (rightSum != sumVector(btemp) && i < B.size())
    {
        btemp = B;
        rightSum = aSum;
        int rear = temp;
        int bnum = btemp[i];
        btemp[i] = rear;
        rightSum += bnum;
        i++;
    }
    res.push_back(B[i - 1]);
    return res;
}

int main()
{
    vector<int> a = {1, 2, 5};
    vector<int> b = {2, 4};
    vector<int> res = fairCandySwap(a, b);
    for (auto i : res)
    {
        cout << i << " ";
    }
}