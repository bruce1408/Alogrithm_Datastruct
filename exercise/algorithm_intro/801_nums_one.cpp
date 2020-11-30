#include <iostream>
#include <vector>
using namespace std;

/**
 * 801 求解二进制中的1的个数
 * 
 * 
*/
void nums_one(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0, j = 31;
        while (j--)
        {
            if(a[i] & 1) count++;
            a[i] = a[i] >> 1;
        }
        cout << count << " ";
    }
    cout << endl;
}

/**
 * 方法 2, lowbit(x) = n & (-n)
*/
int lowbit(vector<int>&res)
{
    for(int i=0;i<res.size();i++)
    {
        while(res[i]) res[i] &(-res[i]);
    }
}

int main()
{
    // int n;
    // cin>>n;
    // vector<int>a(n);
    // for(int i=0;i<n;i++) cin>>a[i];
    vector<int> a = {1, 2, 3, 4, 5};
    nums_one(a);
}