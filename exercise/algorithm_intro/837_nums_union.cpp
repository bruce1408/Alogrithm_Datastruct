#include<iostream>
using namespace std;

const int N = 1000010;
int p[N], se[N]; //size表示集合的大小

int find(int x)
{
    
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        p[i] = i;
        se[i] = 1;
    }
    
    while(m--)
    {
        string op;
        cin>>op;
        int x1, x2;
        if(op=="C")
        {
            cin>>x1>>x2;
            // x1 = find(x1), x2 = find(x2);
            if(find(x1) != find(x2))
            {
                se[find(x2)] += se[find(x1)]; // 这里注意先加后合并
                p[find(x1)] = find(x2);
            }
        }
        else if(op=="Q1")
        {
            cin>>x1>>x2;
            if(find(x1)==find(x2)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else
        {
            cin>>x1;
            cout<<se[find(x1)]<<endl;
        }
        
    }
    
}