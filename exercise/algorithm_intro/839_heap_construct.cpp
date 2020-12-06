#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int N = 100010;
int h[N], cnt, ph[N], hp[N];

void heap_swap(int i, int j)
{
    swap(h[i], h[j]);
}
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
    int n, m = 0;
    cin>>n>>m;
    while(n--)
    {
        string s;
        cin>>s;
        int k, x;
        if(s=="I")
        {
            cnt++;
            m++;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        
    }
}
