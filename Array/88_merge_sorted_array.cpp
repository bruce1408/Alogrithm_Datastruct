#include<iostream>
#include<vector>
using namespace std;

// 一般情况，直接比较大小，赋值即可、
vector<int> mergeSortedArray(vector<int> &a, vector<int>&b)
{
    vector<int> res;
    int i=0, j=0;
    while(i<a.size()&& j<b.size())
    {
        if(a[i]<b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else
        {
            res.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size())
    {
        res.push_back(a[i]);
        i++;
    }
    while(j<b.size())
    {
        res.push_back(b[j]);
        j++;
    }
    return res;
}

// 方法二：按照题目要求的来做
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(i>=0 && j>=0)
    {
        nums1[k--] = nums1[i]>nums2[j]?nums1[i--]:nums2[j--];
    }
    while(j>=0)
    {
        nums1[k--] = nums2[j--];
    }
}


int main()
{
    vector<int> a = {1,2,3,4,6,7};
    vector<int> b = {4,5,5,6,7,8,9};
    vector<int>c = mergeSortedArray(a, b);
    for(auto i:c)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;   
}