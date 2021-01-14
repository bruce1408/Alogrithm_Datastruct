#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
/**
 * 分块来求解数组中第k大的元素，考虑数组是随时添加和删除的动态变化
 * 然后使用分块来做
 * 使用两个数组
 * 假设数组总共长度不超过100000，然后设置一个hash的table数组，table[x]表示整数x的当前存在个数
 * 10^5开根号上取整是317，分成317个块，下取整为316，每个块中有316个元素
 * 再定义一个统计的数组block[i]来表示第i块中存在元素的个数，如果要新增一个元素x，那么就计算出x所在的
 * 块号x/316，然后block[x/316]加1，表示块中的元素多了一个，同时table[x]加1，表示整数x的当前存在个数多了1
*/
const int N = 100010;
const int sqrn = 316;

stack<int> st;   // 用栈来插入或者是删除当前数字
int block[sqrn]; // block[i]表示第i个块元素个数
int table[N];    // table[x]表示当前元素存在的个数

void peekMedian(int k)
{
    int sum = 0;
    int idx = 0;
    while (sum + block[idx] < k)
    {
        sum += block[idx++]; // 没有达到k，那么sum累加block[idx]元素个数，如果超过了就跳出
    }
    int num = idx * sqrn; // 找到所在的块的其实元素下标
    while (sum + table[num] < k)
    {
        sum += table[num++]; // 累加块内元素，然后知道sum+到k位置
    }
    printf("find the %dth num: %d\n", k, num);
}

void push_(int x)
{
    st.push(x);        // 入栈
    block[x / sqrn]++; // 对应的块的元素加1
    table[x]++;        // 对应的元素个数加1
}

void pop_()
{
    int x = st.top();  // 获取当前栈顶元素
    st.pop();          // 弹出栈顶元素
    block[x / sqrn]--; // block块中的元素个数--
    table[x]--;        //元素存在个数--
}

int main()
{
    int n = 6, k = 2; // n表示数字个数, k表示求第k个数字
    while (n)
    {
        cout << "请输入整数x：" << endl;
        int x;
        cin >> x;
        push_(x);
        if (st.size() < k)
            cout << "元素个数不够，请继续输入" << endl;
        else
        {
            peekMedian(k);
        }
        n--;
    }
}