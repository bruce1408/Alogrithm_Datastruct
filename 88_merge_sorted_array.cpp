#include<iostream>
#include<vector>
using namespace std;
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