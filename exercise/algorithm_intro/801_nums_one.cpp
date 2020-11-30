#include <iostream>
#include <vector>
using namespace std;

/**
 * 801 求解二进制中的1的个数
 * 
 * 
*/
void nums_one(vector<int> a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0, j = 31;
        while (j--)
        {
            if (a[i] & 1)
                count++;
            a[i] = a[i] >> 1;
        }
        cout << count << " ";
    }
    cout << endl;
}

/**
 * 方法 2, lowbit(x) = n & (-n)；
 * lowbit表示每次减去最后一位1，然后，比如10的二进制是1010， lowbit操作之后返回10，只返回最后一位的1；
 * 然后每次这个数减去lowbit(x)，统计减去的次数就是一个数字里面1的个数
*/
int lowbit(int x)
{
    return x & (-x);
}

int main()
{
    // int n;
    // cin>>n;
    // vector<int>a(n);
    // for(int i=0;i<n;i++) cin>>a[i];
    vector<int> a = {1, 2, 3, 4, 5};
    nums_one(a); // 方法 1

    // 方法 2
    int n = a.size(), i = 0;
    while (i < n)
    {
        int count = 0;
        while (a[i])
        {
            a[i] -= lowbit(a[i]);
            count += 1;
        }
        i++;
        cout << count << " ";
    }
}