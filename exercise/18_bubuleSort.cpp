#include<iostream>
#include<vector>
using namespace std;

/**
 * 冒泡排序，除了把较小的数字要像气泡一样升上来，还要注意效率问题。就是
 * 冒泡排序
*/
vector<int>bubbleSort(vector<int>&res)
{
    int len = res.size();
    for(int i=0;i<len;i++)
    {
        for(int j=len-1;j>=i;j--)
        {
            if(res[j-1]>res[j])
            {
                swap(res[j], res[j-1]);
            }
        }
    }
    return res;
}

/**
 * 但是为了提升效率，比如数组[2,1,3,4,,5,6,7]的情况，只需要交换
 * 2和1，其他不用交换，那么该情况的算法应该优化优化,增加标志位来
 * 判断是否有位置的交换，如果没有交换就不再进行判断。
*/

vector<int>bubbleSort1(vector<int>&res)
{
    int len = res.size();
    int flag = 1;
    while(flag)
    {
        flag=0;
        for(int i=len-1;i>=0;i--)
        {
            if(res[i-1]>res[i])
            {
                swap(res[i], res[i-1]);
                flag=1;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> res = {7,6,4,3,4,1};
    for(auto i:bubbleSort1(res))
    {
        cout<<i<<endl;
    }
}