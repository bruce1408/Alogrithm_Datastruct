#include<iostream>
#include<set>
using namespace std;

// 寻找HAPPY num 特点就是如果不是1的话，那么肯定会出现4.否则就是死循环，不可能出现死循环的，
// 这种题目还是要写出几种情况分析才可以
int valid(int n)  // 数字拆解，然后每个平方和
{
    int sum=0;
    while(n)
    {
        int temp = n%10;
        sum+=temp*temp;
        n/=10;
    }
    return sum;
}

bool isHappy(int n)
{
    set<int> m;
    while(true)
    {
        n = valid(n);
        // 每个新的结果保存，看之前有没有出现过，如果出现且为1，真，否则(一定出现的是4)假。
        if(m.count(n)) // 如果是1的话那么就是返回真，
        {
            if(n==1) return true; 
            else return false; 
        }
        else m.insert(n);
    }
}
int main()
{
    int a = 19;
    cout<<isHappy(a);
    return 0;
}