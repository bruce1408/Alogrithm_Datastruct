#include <string>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
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
    bool operator<(const person &p) const
    {
        return this->age < p.age;
    }
};

/*map example*/
int main()
{
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
    return 0;
}

// #include<string>
// #include<iostream>
// #include<unordered_map>
// using namespace std;

// struct person
// {
// string name;
// int age;

// person(string name, int age)
// {
// this->name =  name;
// this->age = age;
// }

// bool operator== (const person& p) const
// {
// return name==p.name && age==p.age;
// }
// };

// size_t hash_value(const person& p)
// {
// size_t seed = 0;
// std::hash_combine(seed, std::hash_value(p.name));
// std::hash_combine(seed, std::hash_value(p.age));
// return seed;
// }

// int main()
// {
// typedef std::unordered_map<person,int> umap;
// umap m;
// person p1("Tom1",20);
// person p2("Tom2",22);
// person p3("Tom3",22);
// person p4("Tom4",23);
// person p5("Tom5",24);
// m.insert(umap::value_type(p3, 100));
// m.insert(umap::value_type(p4, 100));
// m.insert(umap::value_type(p5, 100));
// m.insert(umap::value_type(p1, 100));
// m.insert(umap::value_type(p2, 100));

// for(umap::iterator iter = m.begin(); iter != m.end(); iter++)
// {
// cout<<iter->first.name<<"\t"<<iter->first.age<<endl;
// }

// return 0;
// }

/* memset example */
// #include <iostream>
// #include <cstring>
// using namespace std;
// int main ()
// {
//   char str[] = "almost every programmer should know memset!";
//   memset (str,'-',6);
//   for(int i=0;i<20;i++)
// 	  cout<<str[i];
//   return 0;
// }

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int main()
// {
//     vector<int> res = {9, 4};
//     unordered_map<vector<int>, int> temp;
//     temp.insert({1, 2}, 4);
// }
