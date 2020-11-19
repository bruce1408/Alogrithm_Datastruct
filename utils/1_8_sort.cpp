#include<iostream>
#include<algorithm>
using namespace std;

/**
 * sort使用algorithm库函数里面的排序算法，
 * 默认的是进行从小到大的排序，也可以从大到小；
 * 例如定义一个结构体，坐标，然后按照结构体的x进行从小到大，这里还需要一个cmp比较函数
 * 如果a.x < b.x 那么就是就是从小到大，反之就是从大到小进行排序
 * 也可以不需要写cmp函数，直接在结构体里面进行运算符重载也可以，x<p.x就是从小到大，否则从大到小进行；
*/
struct Cord
{
    int x, y;
    bool operator<(const Cord & p) const
    {
        return x<p.x; // 从小到大排序, 如果是x>p.x的话，那么就是从大到小排序
    }
} a[6];

bool cmp(Cord a, Cord b)
{
    return a.x < b.x;
}

void print(Cord a[])
{
    for(int i=0;i<6;i++)
    {
        cout<<"("<<a[i].x<<" "<<a[i].y<<")"<<" ";
    }
    cout<<endl;
}

int main()
{
    for(int i=0; i<6;i++)
    {
        a[i].x = -i;
        a[i].y = i;
    }
    print(a);
    // 使用cmp辅助函数来排序
    // sort(a, a+6, cmp);
    // 使用结构体内部重载运算符来进行排序
    sort(a, a+6);

    print(a);
    
}