#include<iostream>
using namespace std;

void prime()
{
    for(int i = 100000;;i++)
    {
        bool flag = true;
        for(int j=2;j*j <=i;j++)
        {
            if(i%j==0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout<<i<<endl;
            break;
        }
    }
    while(1)
    {
        int n;
        cout<<"input a num:"<<endl;
        cin>>n;
        cout<<n%3<<endl;
    }
} 


int main()
{
    prime();
}
  
