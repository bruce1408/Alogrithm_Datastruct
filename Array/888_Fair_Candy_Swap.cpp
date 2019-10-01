#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
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
    while (aSum < partSum && index < A.size())
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

/**
 * 方法 2，方法1太垃圾了，直接看不下去了，用方法 2，非常经典的算法，参考leetcode大佬的一个解答
 * 对于这个问题来说，sumA - A + B = sumB - B + A;对这个等式进行变换，sumA - sumB = 2(A-B)
 * 2A = 2B + (sumA - sumB);所以遍历数组B，在数组中B中要是能找到一个数，加上sumA-sumB的差值满足
 * A即可；
 * 时间复杂度是O(A + B)
*/
vector<int> fairCandySwap1(vector<int> &A, vector<int> &B)
{
    int diff = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
    cout << diff << endl;
    unordered_set<int> st(A.begin(), A.end());
    for (int i : B) // 在B中找一个数加上diff满足他在A数组中即可
    {
        if (st.find(i + diff) != st.end()) // 查找的话我们利用hash_Set，因为hash_set 使用二叉树，效率高的！
            return {i + diff, i};
    }
    return {};
}

/**
 * 方法 3，不利用hash_set来做，而是利用简单的查找，那么在查找那一块，可能时间复杂度是O(A * B + A + B);
 * 时间复杂度明显很高，所以利用hash_set可以明显降低程序的运行时间！
*/
vector<int> fairCandySwap2(vector<int> &A, vector<int> &B)
{
    int aSum = 0, bSum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        aSum += A[i];
    }
    for (int i = 0; i < B.size(); i++)
    {
        bSum += B[i];
    }
    int diff = (aSum - bSum) / 2;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            if (A[i] - B[j] == diff)
            {
                return {A[i], B[j]};
            }
        }
    }
    return {};
}
/**
 * 方法 3，不用unordered_set,那么在查找的那一块时间复杂度就会上升；
 * 思路和方法 2都一样
*/

int main()
{
    vector<int> a = {35, 17, 4, 24, 10};
    vector<int> b = {63, 21};
    vector<int> res = fairCandySwap2(a, b);
    for (auto i : res)
    {
        cout << i << " ";
    }
}