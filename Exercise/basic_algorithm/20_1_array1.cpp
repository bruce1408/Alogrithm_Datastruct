
/**
 * 数组754题，平方矩阵II
 * 输入整数N，输出一个N阶的二维数组。

数组的形式参照样例。

输入格式
输入包含多行，每行包含一个整数N。

当输入行为N=0时，表示输入结束，且该行无需作任何处理。

输出格式
对于每个输入整数N，输出一个满足要求的N阶二维数组。

每个数组占N行，每行包含N个用空格隔开的整数。

每个数组输出完毕后，输出一个空行。

数据范围
0≤N≤100
输入样例：
1
2
3
4
5
0
输出样例：
1

1 2
2 1

1 2 3
2 1 2
3 2 1

1 2 3 4
2 1 2 3
3 2 1 2
4 3 2 1

1 2 3 4 5
2 1 2 3 4
3 2 1 2 3
4 3 2 1 2
5 4 3 2 1
*/

// #include<iostream>
// using namespace std;

// int main()
// {
//     int x;
//     while(cin>>x && x)
//     {
//         for(int i=1;i<=x;i++)
//         {
//             for(int j=1;j<=x;j++)
//             {
                
//                 cout<<abs(i-j)+1<<" ";
//             }
//             cout<<endl;
//         }
//         cout<<endl;
//     }
// }


#include<iostream>
using namespace std;

int q[100][100];
int main()
{
    int n; 
    while(cin>>n && n)
    {
        for(int i=0;i<n;i++)
        {
            q[i][i] = 1;
            for(int j=i+1, k=2; j<n; j++, k++) q[i][j] = k;
            for(int j=i+1, k=2; j<n; j++, k++) q[j][i] = k;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<q[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
