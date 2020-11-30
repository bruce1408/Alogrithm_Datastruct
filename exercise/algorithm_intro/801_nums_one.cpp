#include<iostream>
#include<vector>
using namespace std;

/**
 * 801 求解二进制中的1的个数
 * 
 * 
*/
void nums_one(vector<int> &a)
{
    int i = 0;
    for (int j = 0; j < b.size(); j++)
    {
        if (b[j] == a[i] && i < a.size())
            i++;
    }
    if (i != a.size())
        printf("No");
    else
        printf("Yes");
}


int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    nums_one(a);
}