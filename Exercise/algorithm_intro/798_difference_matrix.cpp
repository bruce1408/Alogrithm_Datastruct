#include<iostream>
using namespace std;

/**
 * 差分矩阵的求解，首先最关键的就是已知数组a，就是前缀和矩阵，然后求解他的差分矩阵
 * 
*/
const int N = 1010;
int n, m , q;
int a[N][N], b[N][N];

//核心就是差分的公式；
void insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1]+=c;
    b[x2+1][y1]-=c;
    b[x1][y2+1]-=c;
    b[x2+1][y2+1]+=c;
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            insert(i, j, i, j, a[i][j]);
        }
    }

    while(q--)
    {
        int x1, y1, x2, y2, c;
        cin>>x1>>y1>>x2>>y2>>c;
        insert(x1, y1, x2, y2, c);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            b[i][j] += b[i][j-1] + b[i-1][j] - b[i-1][j-1]  ;
            printf("%d ", b[i][j]);
        }
        cout<<endl;
    }
}