#include<iostream>
using namespace std;


typedef unsigned long long ULL;
const int N = 100010, P = 131;
int n, m;
char str[N];
ULL h[N], p[N]; // h数组表示前m个字母的哈希值

/**
 * 哈希字符串的目的就是把一个字符串s映射为一个整数，然后让这个
 * 整数可以唯一的表示该字符串；
*/
ULL get(int l, int r)
{
    return h[r] - h[l-1] * p[r-l+1];
}

ULL hashFunc(int l, int r)
{
    int id = 0;
    for(int i= l;i<=r;i++)
    {
        idx = idx * 26 + str[i];
    }
    return id;
}

int main()
{
    cin>>n>>m>>str+1;
    p[0] = 1;
    for(int i=1;i<=n;i++) // h表示字符串前缀子串的哈希值
    {
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + str[i];
    }

    while(m--)
    {
        int l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        // 方法 1
        // if(get(l1, r1) == get(l2, r2)) cout<<"Yes"<<endl;
        // else cout<<"No"<<endl;
        // 方法2；
        if(hashFunc(l1, r1) == hashFunc(l2, r2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}
