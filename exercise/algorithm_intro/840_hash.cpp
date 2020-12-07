#include <iostream>
#include <vector>
using namespace std;

const int N = 100003;
int idx;
/**
 * 模拟散列表，这里使用拉链法来模拟哈希两种操作
 * 第一就是存储
 * 第二就是查找
 * 拉链发就是用除留余数法来确定下标，然后如果有冲突的话，那么就用
 * 拉链法来解决冲突；拉链法使用链表来模拟，
 * 如果这个下标冲突了，那么就在这个下标下继续构建一个单链表存储即可；
*/
void insert(int x, vector<int> &s, vector<int> &ne, vector<int> &h)
{
    int u = (x % N + N) % N;
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
