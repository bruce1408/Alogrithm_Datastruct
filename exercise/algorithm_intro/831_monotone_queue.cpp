#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1000010;

// int a[N], q[N];
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     for(int i=0;i<n;i++) scanf("%d", &a[i]);
//     int head = -1, rear = -1;
//     for(int i=0;i<n;i++)
//     {
//         if(head!=rear &&i-m+1>q[head+1]) head++;
//         while(head!=rear && a[q[rear]]>=a[i]) rear--;
//         q[++rear] = i;
//         if(i>=m-1) printf("%d ", a[q[head+1]]);

//     }
//     cout<<endl;
//     head = -1, rear = -1;
//     for(int i=0;i<n;i++)
//     {
//         if(head!=rear &&i-m+1>q[head+1]) head++;
//         while(head!=rear && a[q[rear]]<=a[i]) rear--;
//         q[++rear] = i;
//         if(i>=m-1) printf("%d ", a[q[head+1]]);

//     }

// }

int q[8];
int main()
{
    int n = 8, m = 3;
    int head = -1, rear = -1;
    int a[8] = {1, 3, -1, -3, 5, 3, 6, 7};
    for (int i = 0; i < n; i++)
    {
        if (head != rear && i - m + 1 >= q[head + 1])
            head++;
        while (head != rear && a[q[head + 1]] >= a[i])
            rear--;
        q[++rear] = i;
        if (i >= m - 1)
            printf("%d ", a[q[head + 1]]);
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;
}