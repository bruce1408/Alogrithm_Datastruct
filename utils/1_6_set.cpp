#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

/**
 * set 和multiset 可以自动对数组中的数进行排序，但是multiset是可以允许重复数字出现！
 * insert 插入
 * iterator 迭代器
 * empty 判断是否为空
 * size 判断set中个数
 * begin() 指向第一个元素的迭代器
 * end() 指向末尾元素的下一个位置
 * clear() 删除set中的所有元素
 * find() 返回给定值的定位器，没有找到返回end()
 * erase(),输入一个数，那么就删除x，输入是迭代器的话就删除这个迭代器
 */

void exampleSet1()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);

    cout << "set 的 size 为： " << s.size() << endl;
    cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;
    cout << "set 中的第一个元素是 ：" << *s.begin() << endl;
    cout << "set 中的最后一个元素是:" << *s.end() << endl;
    set<int>::iterator it;
    // 查找
    if ((it = s.find(2)) != s.end())
        cout << "已经找到： " << *it << endl;
    // 迭代器遍历
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
    cout << "返回第一个大于等于value的值： " << *s.lower_bound(1) << endl;
    cout << "返回最后一个大于value的值： " << *s.upper_bound(2) << endl;
    // 清除集合
    s.clear();
    if (s.empty())
        cout << "set 为空 ！！！" << endl;
    cout << "set 的 size 值为 ：" << s.size() << endl;
    cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;

    // vector
    vector<int> vec = {1, 2, 3, 4, 4, 5, 6};
    set<int> s1(vec.begin(), vec.begin() + 6); // 完整的就是end()
    cout << "set in vec：" << endl;
    for (auto i = s1.begin(); i != s1.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

struct People
{
    string name;
    int age;
    bool operator<(const People p) const //运算符重载
    {
        return age < p.age; //按照年龄由小到大进行排序
    }
};

void exampleSet2()
{
    set<People> s;
    s.insert((People){"张三", 14});
    s.insert((People){"李四", 16});
    s.insert((People){"王二麻子", 10});
    set<People>::iterator it;
    for (it = s.begin(); it != s.end(); it++) //使用迭代器进行遍历
    {
        printf("姓名：%s 年龄：%d\n", (*it).name.c_str(), (*it).age);
    }
}

void exampleSet3()
{
    //multiset 迭代器
    cout << "正向迭代器" << endl;
    multiset<int> res = {1, 4, 2, 3, 3, 5, 6, 7, 8, 2, 9, 1};
    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "res.size() = " << res.size() << endl;

    //multiset 逆向迭代器
    cout << "逆向迭代器" << endl;
    for (auto it = res.rbegin(); it != res.rend(); it++)
    {
        cout << *it << " ";
    }
}

/**
 * 补一个set 和 unordered_set的插入，删除操作的时间比较；
 * lc349 关于这两个进行了复杂度时间的讨论
*/
void intersect()
{
    int first[] = {5, 10, 15, 20, 25};
    int second[] = {50, 40, 30, 20, 10};
    vector<int> v(10); // 0  0  0  0  0  0  0  0  0  0
    vector<int>::iterator it;

    sort(first, first + 5);   //  5 10 15 20 25
    sort(second, second + 5); // 10 20 30 40 50

    it = set_intersection(first, first + 5, second, second + 5, v.begin()); // 10 20 0  0  0  0  0  0  0  0
    v.resize(it - v.begin());                                               // 10 20

    cout << "The intersection has " << (v.size()) << " elements:\n";
    for (it = v.begin(); it != v.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
}

int main()
{
    exampleSet1();
    exampleSet2();
    exampleSet3();
    intersect();
}
