#include <iostream>
using namespace std;

typedef unsigned long long ULL;
const int N = 100010, P = 131;
int n, m;
char str[N];
ULL h[N], p[N]; // h数组表示前m个字母的哈希值

/**
 * 哈希字符串的目的就是把一个字符串s映射为一个整数，然后让这个
 * 整数可以唯一的表示该字符串；
 * 根据定义分别求出hash[i]
 * hash[1]=s1
 * hash[2]=s1∗p+s2
 * hash[3]=s1∗p2+s2∗p+s3
 * hash[4]=s1∗p3+s2∗p2+s3∗p+s4 
 * hash[5]=s1∗p4+s2∗p3+s3∗p2+s4∗p+s5
 * 现在我们想求s3s4的hash值，不难得出为s3∗p+s4,并且从上面观察，
 * 如果看hash[4]−hash[2]并将结果种带有s1,s2系数的项全部消掉，
 * 就是所求。但是由于p的阶数，不能直接消掉，所以问题就转化成，
 * 将hash[2]乘一个关于p的系数，在做差的时候将多余项消除，从而得到结果。
 * 不难发现，对应项系数只差一个p2，而4 - 3 + 1 = 2
 * (待求hash子串下标相减再加一)，这样就不难推导出来此例题的求解式子。
 * hash[4]−hash[2]∗p4−2+1
 * 
*/
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

ULL hashFunc(int l, int r)
{
    int id = 0;
    for (int i = l; i <= r; i++)
    {
        idx = idx * 26 + str[i];
    }
    return id;
}

int main()
{
    cin >> n >> m >> str + 1;
    p[0] = 1;
    for (int i = 1; i <= n; i++) // h表示字符串前缀子串的哈希值
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }

    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        // 方法 1
        // if(get(l1, r1) == get(l2, r2)) cout<<"Yes"<<endl;
        // else cout<<"No"<<endl;
        // 方法2；
        if (hashFunc(l1, r1) == hashFunc(l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
