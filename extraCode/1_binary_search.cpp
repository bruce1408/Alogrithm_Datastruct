#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myfunction(int a, int b)
{
    return a%10>b%10;
}
int binaryS(vector<int>&res, int k)
{
    int left = 0, right = res.size();
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(res[mid]>k)
        {
            right = mid-1;
        }
        else if(res[mid]<k)
        {
            left = mid+1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
    
}

/**
 * search the first index that bigger and equal some num
*/
int binaryS1(vector<int>&res, int k)
{
    for(int i=0; i<res.size(); i++)
    {
        if(res[i]>=k)
        {
            return i;
        }
    }
    return -1;
}

int binaryS1_(vector<int>&res, int k)
{
    int left = 0, right = res.size()-1;
    int mid = (left+right)/2;
    while(left<=right)
    {
        if(res[mid]<=k)
        {
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return right<=res.size()-1?right:-1;
}

int main()
{
    vector<int>res = {1,2,2,2,4,5,6,7,9};
    // cout<<binary_search(res.begin(), res.end(),7)<<endl;
    // cout<<binaryS(res, 8)<<endl;
    // vector<int>::iterator low = lower_bound(res.begin(), res.end(), 2);
    // cout<<low-res.begin()<<endl;
    cout<<binaryS(res, 3)<<endl;
}