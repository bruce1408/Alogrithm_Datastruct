#include<iostream>
#include<vector>
#include"../../utils/cout_vec.h"

using namespace std;

void insert(vector<int>&b, int l, int r, int c)
{
    b[l]+=c;
    b[r+1]-=c;
}


int main()
{
    // int n, m;
    // cin>>n>>m;
    int n = 6, m = 3;
    vector<int>a = {0, 1, 2, 2, 1, 2, 1};
    vector<int>b(n+1);
    // for(int i=1; i<=n; i++)
    //     cin>>a[i]; 
    for(int i=1;i<=n;i++) insert(b, i, i, a[i]);
    print(b);
    
}