#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// 一个数的 完数 就是所有因子相加还是这个数，那么满足题意 28 = 1 + 2 + 4 + 7 + 14
// 我的思路是找出这个数的所有因子，然后相加,超时了

bool checkPerfectNumber(int num) 
{
    // 此方法超时！
    vector<int> res;
    for(int i=1; i<=num/2;i++) // 这个是求所有因子
    {
        if(num%i==0)
        {
            res.push_back(i);
        }
    }
    int sum=0;
    for(auto i:res) sum+=i;
    return sum==num?true:false;
}

// 叼到爆的方法
bool checkPerfectNumber1(int num) 
{
    return num==6 || num==28 || num==496 || num==8128 || num==33550336;
}

// 和求质数的步骤类似 
bool checkPerfectNumber2(int num) 
{
    if(num<=1) return false;
    int sum=1;
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            sum += i + ((num/i==i)?0:num/i);
        }
    }
    return sum;
}
int main()
{
    int a = 28;
    cout<<checkPerfectNumber2(a);
    return 0;
}