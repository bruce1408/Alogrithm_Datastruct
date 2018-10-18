#include<iostream>
using namespace std;
int reverse(int x)
{
    int res=0;
    while(x)
    {
        if(res>INT_MAX/10) return -1;
        res = res*10 + x%10;
        x/=10;
    }
    return res;
}
bool isPalindrome(int x)
{
    if(x<0 ||(x%10==0&&x!=0)) return false;
    return reverse(x)==x;
}

int main()
{
    int x ;
    cout<<"input a num: ";
    cin>>x;
    cout<<isPalindrome(x)<<endl;
    return 0;
}