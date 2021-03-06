#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/**
 * kmp 算法
 *  给定一个模式串S，以及一个模板串P，所有字符串中只包含大小写英文字母以及阿拉伯数字。
 * 模板串P在模式串S中多次作为子串出现。
 * 求出模板串P在模式串S中所有出现的位置的起始下标。
*/

/**
 * 方法 1，使用双指针来做，超时
*/
void kmp1()
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
 * 手动测试例子
*/
const int N1 = 1000010, M1 = 1000010;

int n1, m1;
int ne1[N1];
char s1[M1], p1[N1];

void kmp2()
{
    // cin >> n >> p + 1 >> m >> s + 1;
    n1 = 3, m1 = 5;
    p1[1] = 'a';
    p1[2] = 'b';
    p1[3] = 'a';

    s1[1] = 'a';
    s1[2] = 'b';
    s1[3] = 'a';
    s1[4] = 'b';
    s1[5] = 'a';

    // s = "ababa";
    for (int i = 2, j = 0; i <= n1; i++)
    {
        while (j && p1[i] != p1[j + 1])
            j = ne1[j];
        if (p1[i] == p1[j + 1])
            j++;
        ne1[i] = j;
    }
    // 匹配成功
    for (int i = 1, j = 0; i <= m1; i++)
    {
        // j是否是从0开始还是
        while (j && s1[i] != p1[j + 1])
            j = ne1[j];
        if (s1[i] == p1[j + 1])
            j++;
        if (j == n1)
        {
            printf("%d ", i - n1);
            j = ne1[j];
        }
    }
    cout << endl;
    for (int i = 0; i <= m1; i++)
        cout << ne1[i] << " ";
    cout << endl;
}

/**
 * 方法 3，手写kmp版本
*/
const int N2 = 1000010, M2 = 1000010;
char ne[N2], s[M2], p[N2];
int n2, m2;

void kmp3()
{
    // cin>>n>>p+1>>m>>s+1;
    // s = ababa, p = aba
    n2 = 3, m2 = 5;
    p[1] = 'a';
    p[2] = 'b';
    p[3] = 'a';

    s[1] = 'a';
    s[2] = 'b';
    s[3] = 'a';
    s[4] = 'b';
    s[5] = 'a';
    /**
     * 这里的下标都是从1开始
     * next数组构建过程，这里都从数组的下标1开始
     * */
    for (int i = 2, j = 0; i <= n2; i++)
    {
        while (j && p[i] != p[j + 1]) // 反复令j=next[j]，直到j退回到0；或者p[i]==p[j+1]
            j = ne[j];
        if (p[i] == p[j + 1]) // 如果p[i] ==p[j+1],则令next[i] = j+1;
            j++;
        ne[i] = j; // 否则next[i] = j;
    }
    // 匹配过程
    for (int i = 1, j = 0; i <= m2; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n2) // 匹配成功
        {
            printf("%d ", i - n2);
            // j = ne[j];
        }
    }
}

/*================================================next 数组生成方式========================================================*/
/**
 * next数组构成方法 1，不推荐版本，冗余
*/
void getnext1()
{
    string s = "abababc";
    int n = s.size();
    vector<int> ne(n, -1);
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        if (s[i] == s[ne[j] + 1])
            ne[i] = ne[j] + 1;
        else
        {
            while (j >= 0)
            {
                if (s[i] == s[ne[j] + 1])
                {
                    ne[i] = ne[j] + 1;
                    break;
                }
                else
                    j = ne[j];
            }
        }
    }

    for (auto i : ne)
    {
        cout << i << " ";
    }
    cout << endl;
}

/**
 * next数组构成方法 2，使用双指针算法来做
 * next[i]表示s[0]~ s[i]字符串中最长相等的前后缀中前缀的最后一位
 * 比如字符串如：     a b a b c a a b c
 * 得到的next数组为： -1 -1 0 1 -1 0 0 1 2
*/
vector<int> getnext2(string s)
{
    // string s = "ababaab";
    int j = -1;
    vector<int> ne(s.size(), -1);
    for (int i = 1; i < s.size(); i++)
    {
        while (j != -1 && s[i] != s[j + 1]) // j不能等于第一个数且
            j = ne[j];
        if (s[i] == s[j + 1])
            j++;
        ne[i] = j;
    }
    return ne;
}

int kmp4(string s, string p)
{
    int m = p.size(), j = -1;
    vector<int> ne = getnext2(p);
    for (int i = 0; i < s.size(); i++)
    {
        while (j != -1 && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == m - 1)
            return i - m + 1;
    }
    return -1;
}

/**
 * 方法 3，next数组生成
*/
vector<int> getNext3(string str)
{
    int len = str.size();
    vector<int> next(len, -1);
    int i = 0;
    next[i] = -1;
    int j = -1;
    while (i < len)
    {
        if (j == -1 || str[i] == str[j]) //循环的if部分
        {
            ++i;
            ++j;
            //修正的地方就发生下面这4行
            if (str[i] != str[j]) //++i，++j之后，再次判断ptrn[i]与ptrn[j]的关系
                next[i] = j;      //之前的错误解法就在于整个判断只有这一句。
            else
                next[i] = next[j]; //这里其实是优化了后的，也可以仍是next[i]=j
            //当str[i]==str[j]时，如果str[i]匹配失败，那么换成str[j]肯定也匹配失败，
            //所以不是令next[i]=j，而是next[i] = next[j]，跳过了第j个字符，
            //即省去了不必要的比较
            //非优化前的next[i]表示前i个字符中前缀与后缀相同的最大长度
        }
        else //循环的else部分
            j = next[j];
    }
    return next;
}

int main()
{
    // kmp1();
    // generat();
    // getnext1();
    auto res = getnext2("abcdabc");
    for (auto i : res)
        cout << i << " ";
    cout << endl;

    // 第二种求解方法
    auto res1 = getNext3("abcdabc");
    for (auto i : res1)
        cout << i << " ";
    cout << endl;

    cout << kmp4("ababcd", "abc") << endl;
}