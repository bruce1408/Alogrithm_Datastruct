// C++ program to demonstrate functionality of unordered_map
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * unordered_map 关联容器的一种，存储无序的键值对
 * 插入元素可以像数组下标赋值那样来插入元素，也可以insert函数插入一个pair对；其中
 * 数据类型要和map的数据类型一样
 * 
 * 查找有两种方式，第一种就是find函数，如果map.find(num) != map.end()，那么找到这个数
 * 否者是没有找到，第二种就是count函数，如果map.count(num)返回的是个数，如果个数是0说明也没有找到
 * 
 * 遍历map，使用范围for循环，或者是迭代器
 * 
*/

#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, double> umap;
    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;
    // 插入新元素， make_pair在pair文档里说明具体用法
    umap.insert(make_pair("e", 2.718));
    string key = "e";
    if (umap.find(key) == umap.end())
        cout << key << " not found\n\n";
    else
        cout << "Found " << key << "\n\n";
    key = "lambda";
    if (umap.count(key) == 0)
        cout << key << " not found\n";
    else
        cout << "Found " << key << endl;

    cout << "\nAll Elements : \n";
    // 第一种遍历方式
    unordered_map<string, double>::iterator itr;
    for (itr = umap.begin(); itr != umap.end(); itr++)
    {
        cout << itr->first << "  " << itr->second << endl;
    }
    cout << "\nAll Elements : \n";
    // 第二种遍历方式
    for (auto x : umap)
        cout << x.first << " " << x.second << endl;
}