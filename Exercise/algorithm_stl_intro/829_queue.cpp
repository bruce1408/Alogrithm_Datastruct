#include<iostream>
using namespace std;

const int N = 100010;
int s[N], head = -1, rear = -1;

int push(int x)
{
    s[++rear] = x;
}

void pop()
{
    head++;
}

int query()
{
    return s[head+1];
}

string empty()
{
    if(head==rear) return "YES";
    else return "NO";
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        string t;
        cin>>t;
        if(t=="push")
        {
            cin>>m;
            push(m);
        }
        else if(t=="query") cout<<query()<<endl;
        else if(t=="pop") pop();
        else cout<<empty()<<endl;
    }
    
        
}