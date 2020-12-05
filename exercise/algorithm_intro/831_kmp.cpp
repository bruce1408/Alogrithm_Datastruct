#include <iostream>
#include <cstdio>
using namespace std;

/**
 * kmp 算法
 *  给定一个模式串S，以及一个模板串P，所有字符串中只包含大小写英文字母以及阿拉伯数字。
 * 模板串P在模式串S中多次作为子串出现。
 * 求出模板串P在模式串S中所有出现的位置的起始下标。
*/

/**
 * 方法 1，使用双指针来做，可能会超时
*/
void kmpBF()
{
    int m = 3, n = 5;
    string s = "ababa";
    string p = "aba";
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            if (s[i + j] != p[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << i << " ";
    }
    cout << endl;
}

/**
 * 方法 2，优化双指针算法，使用next数组，用kmp算法来做
*/
// const int N = 1000010, M = 1000010;

// int n, m;
// int ne[N];
// char s[M], p[N];

// int main()
// {
//     // cin >> n >> p + 1 >> m >> s + 1;
//     n = 6, m = 5;
//     // p+1 = "aba";
//     p[1] = 'a';
//     p[2] = 'b';
//     p[3] = 'a';
//     p[4] = 'b';
//     p[5] = 'a';
//     p[6] = 'a';


//     s[1] = 'a';
//     s[2] = 'b';
//     s[3] = 'a';
//     s[4] = 'b';
//     s[5] = 'a';

//     // s = "ababa";
//     for (int i = 2, j = 0; i <= n; i++)
//     {
//         while (j && p[i] != p[j + 1])
//             j = ne[j];
//         if (p[i] == p[j + 1])
//             j++;
//         ne[i] = j;
//     }
//     // 匹配成功
//     for (int i = 1, j = 0; i <= m; i++)
//     {
//         // j是否是从0开始还是
//         while (j && s[i] != p[j + 1])
//             j = ne[j];
//         if (s[i] == p[j + 1])
//             j++;
//         if (j == n)
//         {
//             printf("%d ", i - n);
//             j = ne[j];
//         }
//     }
//     cout<<endl;
//     for(int i=0;i<=m;i++)
//     {
//         cout<<ne[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }


const int N = 100010;
char ne[N], s[N], p[N];

int n, m;

int main()
{
    cin>>n>>p+1>>m>>s+1;

    // next数组构建过程，这里都从数组的下标1开始
    for(int i=2, j=0; i<=n; i++)
    {
        
    }
    // 匹配过程
    
}