#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

/**
 * Given a non-negative index k where k ≤ 33, 
 * return the kth index row of the Pascal's triangle.
 * Note that the row index starts from 0.
 * 
 * Example:
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 给一个数字，然后返回的是这个杨辉三角的第k层的数组，杨辉三角
 * 层数从0开始技计数；
 * 这个题目有要求，只用O(k)的额外空间即可；
*/

vector<int> getRow(int rowIndex) 
{
    vector<int>res(rowIndex+1, 1);
    for(int i=1;i<rowIndex;i++)
    {
        res[i] = rowIndex+;
    }
}

int main()
{
    int num = 5;
    for(auto x:getRow(num))
    {
        cout<<x<<" ";
    }
}
