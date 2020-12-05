#include <iostream>
using namespace std;

const int N = 100010;
/**
 * trie树用来高效存储和查找字符串集合的数据结构
 * son表示N节点的所有子节点存的位置
 * */

int son[N][26], cnt[N], idx; // 下标是0，是根节点也是空节点
char str[N];

void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }

    cnt[p]++;
}

int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

// int main()
// {
//     int n;
//     cin>>n;
//     while(n--)
//     {
//         char op[2];
//         scanf("%s%s", op, str);
//         if(op[0]=='I') insert(str);
//         else printf("%d\n",query(str));
//     }
// }

int main()
{
    // char op[1];
    char str[] = {"hello i am"};
    char str1[] = "hello i am";
    printf("%d, ", sizeof(str));
    printf("%d", sizeof(str1));
    // scanf("%s", op);
    // cout << "op[0] is: " << op[0] << endl;
    // // for (int i = 0; i < 2; i++)
    // // {
    // //     cout << op[0] << " ";
    // // }
    cout << endl;
}