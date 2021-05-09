#include<iostream>
using namespace std;

string reverse_str(int l, int r, string &s)
{
    for(int i = l-1; i<r;i++)
    {
        if(s[i] & 1) s[i] = '0';
        else s[i] = '1';
    }
    return s;
}


int main()
{
    int n , m;
    cin>>n>>m;
    string s ;
    cin>>s;
    while(m--)
    {
        int l , r;
        cin>>l>>r;
        cout<<reverse_str(l, r, s)<<endl;
    }
}