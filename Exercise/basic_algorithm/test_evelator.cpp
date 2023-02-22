#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    
    int sum = 0;
    int m = n, k = 0;
    
    while(m--)
    {
        cin>>res[k++];
    }
    sum += res[0] * 6;
    for(int i = 1;i<n;i++)
    {
        if(res[i] > res[i-1]) sum +=6*(res[i] - res[i-1]);
        else sum+= 4*(res[i-1] - res[i]);
    }
    
    sum += 5 * n;
    cout<<sum<<endl;
    return sum;
    
}