#include<iostream>
#include<vector>
using namespace std;
/**
 * 冒泡排序的核心思想是两两比较相邻的关键字，如果是反序的就交换，直到没有反序情况为止。
*/
void print(vector<int>res)
{
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}


/**
 * 严格来讲不是bubuleSort，因为并没有两两交换，只能看作是最简单的交换排序而已，这种算法的效率很低
 */
void bubble(vector<int>&res)
{
    for(int i=0;i<res.size();i++)
    {
        for(int j=i+1;j<res.size();j++)
        {
            if(res[i]>res[j])
            {
                swap(res[i], res[j]);
            }
        }
    }
}
/**
 * 冒泡排序，除了把较小的数字要像气泡一样升上来，还要注意效率问题。就是两两交换，i从0到n-1，j从当前长度到i进行两两
 * 对比，然后小的值就上移，这样第一个i结束之后得到最小的数，同时其他小的数也上移了，效率高很多。
*/
vector<int>bubbleSort(vector<int>&res)
{
    int len = res.size();
    for(int i=0;i<len;i++)
    {
        for(int j=len-1;j>=i;j--)
        {
            if(res[j-1]>res[j]) // 如果前一个大于后一个，那么就交换位置即可
            {
                swap(res[j], res[j-1]);
            }
        }
    }
    return res;
}

/**
 * 但是为了提升效率，比如数组[2,1,3,4,5,6,7]的情况，只需要交换
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

/**
 * 冒泡排序的一种改进方法，和上面的思路是一样的，但是优化了一个标志位，
 * 在有交换的时候才进行判断，否则不再进行遍历
*/
vector<int>bubbleSort2(vector<int>&res)
{
    int len = res.size();
    int flag = 1;
    for(int i=0;i<len && flag;i++)
    {
        flag = 0;
        for(int j=len-1;j>=i;j--)
        {
            if(res[j-1] > res[j] )
            {
                swap(res[j], res[j-1]);
                flag = 1;
            }
        }
    }
    return res;
}


int main()
{
    vector<int> res = {7,6,4,3,4,1};
    // print(bubbleSort1(res));
    print(bubbleSort2(res));
    // bubble(res);
    // print(res);
    
}