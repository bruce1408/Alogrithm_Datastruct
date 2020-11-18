
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

/**
 * map 类似于 python 的字典
 * Map是STL的一个关联容器，它提供一对一（其中第一个可以称为关键字，每个关键字只能在map中出现一次，第二个可能称为该关键字的值
 * 的数据 处理能力，由于这个特性，它完成有可能在我们处理一对一数据的时候，在编程上提供快速通道。这里说下map内部数据的组织，
 * map内部自建一颗红黑树(一 种非严格意义上的平衡二叉树)，这颗树具有对数据自动排序的功能，所以在map内部所有的数据都是有序的，
 * 后边我们会见识到有序的好处。
 * 
 * insert 插入对象 make_pair 和 pair两种，make_pair不需要写出类型，pair需要写出数据的类型
 * 比如：
 * m.insert(make_pair("Tom3", 100));
 * m.insert(pair<int, string>(2, "student_two"));  

*/

/**
 * 主要介绍C++11 新特性： unordered_map 与 map 的对比
 * 
 *                   | map             | unordered_map
 * ---------------------------------------------------------
 * Ordering        | increasing  order   | no ordering
 *                 | (by default)        |
 * 
 * Implementation  | Self balancing BST  | Hash Table
 *                 | like Red-Black Tree |  
 * 
 * search time     | log(n)              | O(1) -> Average 
 *                 |                     | O(n) -> Worst Case
 *
 * Insertion time  | log(n) + Rebalance  | Same as search
 *                       
 * Deletion time   | log(n) + Rebalance  | Same as search
 * 
 * */
struct person
{
    string name;
    int age;
    person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    // 运算符重载,
    bool operator < (const person & p) const
    {
        return this->age  < p.age;
    }
};

/**
 * 数据的插入--第一种：使用insert函数插入make_pair数据
*/
void mapexample1()
{
    cout<<"====== mapexample(): ======"<<endl;
    map<person, int> m;
    person p1("Tom1", 20);
    person p2("Tom2", 22);
    person p3("Tom3", 22);
    person p4("Tom4", 23);
    person p5("Tom5", 24);
    m.insert(make_pair(p3, 100));
    m.insert(make_pair(p4, 100));
    m.insert(make_pair(p5, 100));
    m.insert(make_pair(p1, 100));
    m.insert(make_pair(p2, 100));
    //迭代方法1 map
    for (map<person, int>::iterator iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first.name << "\t" << iter->first.age << endl;
    }
    // 迭代方法2 map
    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->first.age << " " << i->first.name << endl;
    }
}

struct person1
{
    string name;
    int age;

    person1(string name, int age)
    {
        this->name =  name;
        this->age = age;
    }

    bool operator== (const person1& p) const
    {
        return name==p.name && age==p.age;
    }
};

/**
 * 数据的插入--第二种：用insert函数插入pair数据
 * */  
void mapexample2()  
{  
    cout<<"====== mapexample2(): ======"<<endl;
    map<int, string> mapStudent;  
    mapStudent.insert(pair<int, string>(1, "student_one"));  
    mapStudent.insert(pair<int, string>(2, "student_two"));  
    mapStudent.insert(pair<int, string>(3, "student_three"));  
    map<int, string>::iterator iter;  
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
    {
        cout<<iter->first<<' '<<iter->second<<endl; 
    }
}  

/**
 * 数据的插入--第三种：使用insert函数插入value_type数据
*/
void mapexample3()  
{  
    cout<<"====== mapexample3(): ======"<<endl;
    map<int, string> mapStudent;  
    mapStudent.insert(map<int, string>::value_type (1, "student_one")); 
    mapStudent.insert(map<int, string>::value_type (2, "student_two"));  
    mapStudent.insert(map<int, string>::value_type (3, "student_three"));  
    map<int, string>::iterator iter;  
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)  
        cout<<iter->first<<' '<<iter->second<<endl; 
}

/**
 * 数据的插入--第四种：使用insert函数，使用数组的形式
*/
void mapexample4()
{
    cout<<"====== mapexample4(): ======"<<endl;
    map<int, string> mapStudent;  
    mapStudent[1] = "student_one";  
    mapStudent[2] = "student_two";  
    mapStudent[3] = "student_three";  
    map<int, string>::iterator iter;  
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)  
        cout<<iter->first<<' '<<iter->second<<endl;  
}

int main()
{
    mapexample1();
    mapexample2();
    mapexample3();
    mapexample4();

    //memset example
    char str[] = "almost every programmer should know memset!";
    memset (str,'-',6);
    for(int i=0;i<20;i++) cout<<str[i];

    vector<int> res = {9, 4};
    // unordered_map<vector<int>, int> temp;
    // temp.insert(make_pair<vector<int>, int> (res, 4));
}
