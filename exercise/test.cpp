// vector the process of elements to push in the vector
#include<iostream>
#include<vector>
using namespace std;


// 最大子序列和
int maxsequence3(vector<int>&a, int len)
{
    int maxsum, maxhere;
    maxsum = maxhere = a[0];   //初始化最大和为a【0】
    for (int i=1; i<len; i++) {
        if (maxhere <= 0)
            maxhere = a[i];  //如果前面位置最大连续子序列和小于等于0，则以当前位置i结尾的最大连续子序列和为a[i]
        else
            maxhere += a[i]; //如果前面位置最大连续子序列和大于0，则以当前位置i结尾的最大连续子序列和为它们两者之和
        if (maxhere > maxsum) {
            maxsum = maxhere;  //更新最大连续子序列和
        }
    }
    return maxsum;
}


int main()
{
    vector<vector<int>>res;
    res = {{1,2}}; // 这种方式每次只装入一次即可，是最后一次
    res = {{4,5}}; // 最后更新的是4,5装入了容器，而1,2 没有装入容器；
    res.push_back({2,3});
    for(auto x:res)
    {
        for(auto i:x)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    vector<int>num = {2,-4, 3, 5,-3};
    cout<<maxsequence3(num, 4)<<endl;
}
