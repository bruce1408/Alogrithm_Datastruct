#include<iostream>
using namespace std;

int integerReplacement(int n)
{
    int count=0;
    while(n!=1)
    {
        if(n%2!=0)
        {
            cout<<n<<endl;
            n = n-1; // n+1 是17 找到最小的才可以；
            count++;
        }
        count++;
        n/=2;
    }
    return count;
}


int integerReplacement1(int n) 
{
    int res = 0;
    if(n == INT_MAX){n/=2;res++;} // 对溢出操作直接定义；
    while(n != 1)
    {
        // 研究发现，除了7和3，所有其他加1是4的倍数的奇数，都适合加1操作；
        if(n%2) 
        {
            if( (n+1)%4 == 0 && n!=3) n+=1;
            else n-=1;
        }
        else 
            n/=2;
        res++;
    }
    return res;
}


int integerReplacement2(int n)
{
    if(n==1) return 0;
    if(n%2==0) return 1 + integerReplacement2(n/2);
    else
    {
        long long t = n; // 考虑溢出操作
        return 2 + 
        min(integerReplacement2((t+1)/2),integerReplacement2((t-1)/2));
    }
}

int main()
{
    int n;
    cout<<"input a num: ";
    cin>>n;
    cout<<integerReplacement(n)<<endl;
    return 0;
}