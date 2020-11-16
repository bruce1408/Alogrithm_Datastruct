#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
    int n=4,size=2;
    int a[4] = {0,0,1,2};
    set<int> a1(a, &a[size]);
    for(auto i:a1)
    {
        cout<<i<<endl;
    }
    cout<<a1.size()+n-size<<endl;
    vector<int> vec = {0,0,1,2,3,4,1};
    set<int>s(vec.begin(), vec.end());
    for(auto i: s)
    {
        cout<<i<<endl;
    }

}