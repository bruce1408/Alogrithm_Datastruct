#include<iostream>
#include<vector>
using namespace std;

/**
 * Given an integer n, return any array containing n unique integers such that they add up to 0.
 * 给一个数字,然后返回数组,这个数组的和加起来是0,且数组元素不重复
 * 
 * Example 1:
 * Input: n = 5
 * Output: [-7,-1,1,3,4]
 * Explanation: These arrays also are accepted [-5,-1,1,2,3], [-3,-1,2,-2,4].
 * 
 * Example 2:
 * Input: n = 3
 * Output: [-1,0,1]
*/

/**
 * 方法 1, 区分n这个数字是偶数还是奇数,如果是偶数的话那么
 * 从长度一半开始,每次把这个数的相反数装进数组,最后如果是奇数的话,
 * 那么就把0放进去即可
 * 比如n=6; n/2=3;res = [3,2,1,-1,-2,-3]
 * 如果n=7;n/2最后在res里面添加上0即可
*/
vector<int> sumZero(int n)
{
    vector<int>res;
    int num = n, count = n/2;
    while(count)
    {
        res.push_back(num);
        res.push_back(num*-1);
        num--;
        count--;
    }
    if(n%2!=0)
    {res.push_back(0);}
    return res;
}


/**
 * 方法 2, 就是利用的是一个特殊的公式,
 * a[i] = i*2 - n + 1
 * 时间复杂度高于方法 1;
*/
vector<int>sumZero1(int n)
{
    vector<int> res(n, 0);
    for(int i=0;i<n;i++)
    {
        res[i] = i*2 - n + 1;
    }
    return res;
}

int main()
{
    for(auto i:sumZero1(6))
    {
        cout<<i<<" ";
    }
}