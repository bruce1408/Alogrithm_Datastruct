#include<iostream>
#include<cmath>
using namespace std;

int t[100][100];

int main()
{
    int n=3, m=3;
    // cin>>n>>m;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    
    for(int i=0, j=0, d=0, k=1; k<=n*m;k++)
    {
        t[i][j] = k;
        int a = i+dx[d], b = j+dy[d];
        if(a<0 || a>=n || b<0 || b>=m || t[a][b])
        {
            d = (d+1)%4;
            a = i+dx[d], b = j+dy[d];
        }
        
        i = a, j = b;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    
}


#include <iostream>

using namespace std;
const int N = 105;

int a[N][N];
int n, m;

int main() {
    cin >> n >> m;

    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    int k = 1;
    while (left <= right && top <= bottom) {
        for (int i = left ; i <= right; i ++) {
            a[top][i] = k ++;
        }
        for (int i = top + 1; i <= bottom; i ++) {
            a[i][right] = k ++;
        }
        for (int i = right - 1; i >= left && top < bottom; i --) {
            a[bottom][i] = k ++;
        }
        for (int i = bottom - 1; i > top && left < right; i --) {
            a[i][left] = k ++;
        }
        left ++, right --, top ++, bottom --;
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}