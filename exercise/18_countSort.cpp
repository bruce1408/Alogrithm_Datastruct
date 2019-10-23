#include<iostream>
#include<vector>
using namespace std;

/**
 * 计数排序，找到数组中的最大值和最小值，然后统计每个元素出现的
 * 次数，放在新的数组中去，然后
*/
vector<int>countSort(vector<int>&res)
{
    int maxNum = res[0], minNum = res[1];
    for(int i=0;i<res.size();i++)
    {
        if(res[i]>maxNum) maxNum = max(maxNum, res[i]);
        if(res[i]<=minNum) minNum = min(minNum, res[i]);
    }
    vector<int>temp(maxNum+1);
    for(int i=0;i<res.size();i++) temp[res[i]]++;
    int k =0;
    for(int j=0;j<temp.size();j++)
    {
        while(temp[j]>0)
        {
            res[k++] = j;
            temp[j]--;
        }
    }
    return res;
}

int main()
{
    vector<int> res = {5,1,9,3,7,4,8,6,1};
  
    for(auto i:countSort(res))
    {
        cout<<i<<endl;
    }
}