
#include<iostream>
using namespace std;

const int N = 100010;
int h[N], se;

/**
 * 
*/
void down(int index)
{
    int t = index;
    
    if(2 * index <= se && h[2*index] < h[t]) t = 2 * index;
    if(2 * index + 1 <= se && h[2*index+1] < h[t]) t = 2 * index+1;
    if(index != t) 
    {
        swap(h[t], h[index]);
        down(t);
    }
    
}

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>h[i];
    se = n;
    for(int i=n/2;i>=0;i--)
    {
        down(i);
    }

    while(m--)
    {
        cout<<h[1]<<" ";
        h[1] = h[se];
        se--;
        down(1);
    }
}
