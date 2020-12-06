#include<iostream>
using namespace std;

const int N = 1000010;
int p[N];

int find(int x)
{
    // 这里没有用到路径压缩，所以可能超时
    // while(x!=p[x])
    // {
    //     x = p[x];
    // }
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i] = i;
    
    while(m--)
    {
        string op;
        cin>>op;
        int x1, x2;
        cin>>x1>>x2;
        if(op=="M")
        {
            
            p[find(x1)] = find(x2);
            
        }
        else
        {
            if(find(x1)==find(x2)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    
}