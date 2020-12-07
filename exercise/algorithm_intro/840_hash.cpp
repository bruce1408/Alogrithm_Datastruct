#include <iostream>
#include <vector>
using namespace std;

/**
 * 开放寻址法来模拟哈希表
 * 只开了一个一维数组，长度是2-3倍的数据范围
 * null 表示数组的这个数是空的，不在数据范围即可 
*/
const int N = 200003, null = 0x3f3f3f3f;
int h[N];

/**
 * 方法 1，find函数，首先对x进行存储，看h所在下标是不是不为空，且有其他值，那么
 * 就往后看，如果看到最后一个数了，那么这个时候从头开始看，是不是有空位可以插进去
 * 最后返回插入的位置，所以find函数，当这个数字存在，返回下标，当这个数字不存在，返回
 * 插入的位置；
*/
int find(int x)
{
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x)
    {
        t++;
        if (t == N)
            t = 0;
    }
    return t;
}

int main()
{
    memset(h, 0x3f, sizeof h); // 初始化所有数字为一个特殊字
    int n;
    scanf("%d", &n);

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'I')
            h[find(x)] = x;
        else
        {
            if (h[find(x)] == null)
                puts("No");
            else
                puts("Yes");
        }
    }
    return 0;
}

/**
 * 模拟散列表，这里使用拉链法来模拟哈希两种操作
 * 第一就是存储
 * 第二就是查找
 * 拉链发就是用除留余数法来确定下标，然后如果有冲突的话，那么就用
 * 拉链法来解决冲突；拉链法使用链表来模拟，
 * 如果这个下标冲突了，那么就在这个下标下继续构建一个单链表存储即可；
*/
const int N = 100003;
int idx;

void insert(int x, vector<int> &s, vector<int> &ne, vector<int> &h)
{
    int u = (x % N + N) % N; // 这里注意负数的话余数处理
    s[idx] = x;
    ne[idx] = h[u];
    h[u] = idx;
    idx++;
}

bool find(int x, vector<int> &h, vector<int> &s, vector<int> &ne)
{
    int u = (x % N + N) % N;
    if (h[u] != -1)
    {
        for (int i = h[u]; i != -1; i = ne[i])
        {
            if (s[i] == x)
                return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<int> ne(N);
    vector<int> s(N);
    vector<int> h(N, -1);
    int n;
    cin >> n;
    string str;
    while (n--)
    {
        int x;
        cin >> str >> x;
        if (str == "I")
        {
            insert(x, s, ne, h);
        }
        else
        {
            if (find(x, h, s, ne))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
