#include<iostream>
using namespace std;

int lcm(int a, int b)
{
    int res = 1;
    while(a%b!=0)
    {
        int z = a;
        a = b;
        b = z%b;
    }
    res = b;
    return res;
}

int main()
{
    int x, y;
    x = 12, y = 16;
    cout<<lcm(x, y)<<endl;
}