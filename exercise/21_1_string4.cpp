#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s = "you want some", t="you", p="i", r;
    
    // getline(cin, s);
    // getline(cin, t);
    // getline(cin, p);
    int i=0,j=0;
    while(i<s.size())
    {
        if(s[i]==t[j] && j<t.size())
        {
            i++;
            j++;
        }
        else if(i==j && j==t.size())
        {
            r+=p;
            i++;
        }
        else
        {
            r+=s[i];
            i++;
        }
    }
    cout<<r<<endl;
}