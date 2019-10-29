// vector the process of elements to push in the vector
#include<iostream>
#include<vector>
using namespace std;

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
}