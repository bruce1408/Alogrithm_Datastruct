#include <iostream>
using namespace std;

const int N = 100010;
/**
 * trie树用来高效存储和查找字符串集合的数据结构
 * son表示N节点的所有子节点存的位置
 * */

int son[N][26], cnt[N], idx; // 下标是0，是根节点也是空节点
// char str[N];

void insert(string str)
{
    int p = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }

    cnt[p]++;
}

int query(string str)
{
    int p = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    // int n = 2;
    // while (n--)
    // {
    //     string op, str;
    //     cin >> op >> str;
    //     // char op[2] = "I";
    //     // scanf("%s%s", op, str);
    //     if (op == "I")
    //         insert(str);
    //     else
    //         printf("%d\n", query(str));
    // }

    string op, str;
    op = "I", str = "abab";
    // char op[2] = "I";
    // scanf("%s%s", op, str);
    if (op == "I")
        insert(str);
    else
        printf("%d\n", query(str));

    op = "q", str = "bac";
    if (op == "I")
        insert(str);
    else
        printf("%d\n", query(str));
}