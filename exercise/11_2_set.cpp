#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

// set 和multiset 可以自动对数组中的数进行排序，但是multiset是可以允许重复数字出现！

void exampleSet1()
{
    set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);

    cout<<"set 的 size 为： "<<s.size()<<endl;
    cout<<"set 的 maxsize的值为 ："<<s.max_size()<<endl;
    cout<<"set 中的第一个元素是 ："<<*s.begin()<<endl;
    cout<<"set 中的最后一个元素是:"<<*s.end()<<endl;
    set<int>::iterator it;
    
    // 查找
    if((it = s.find(2)) != s.end())
    {
        cout<<"已经找到： "<<*it<<endl;
    }

    // 迭代器遍历
    for(set<int>::iterator it = s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<endl;
    }

    // 找到返回第一个大于等于value的定位器
    cout<<"返回第一个大于等于value的值： "<<*s.lower_bound(1)<<endl;
    
    // 找到返回最后一个大于等于value的定位器
    cout<<"返回最后一个大于等于value的值： "<<*s.upper_bound(2)<<endl;
    // 清除集合
    s.clear();
    if(s.empty())
    {
        cout<<"set 为空 ！！！"<<endl;
    }
    cout<<"set 的 size 值为 ："<<s.size()<<endl;
    cout<<"set 的 maxsize的值为 ："<<s.max_size()<<endl;    
}

struct People  
{  
    string name;  
    int age;  
    bool operator <(const People p) const  //运算符重载   
    {  
        return age<p.age;       //按照年龄由小到大进行排序   
    }  
};   

void exampleSet2()  
{     
    set<People>s;  
    s.insert((People){"张三",14});  
    s.insert((People){"李四",16});  
    s.insert((People){"王二麻子",10});  
    set<People>::iterator it;              
    for(it=s.begin();it!=s.end();it++)  //使用迭代器进行遍历   
    {  
        printf("姓名：%s 年龄：%d\n",(*it).name.c_str(),(*it).age);  
    }   
}  

int main()
{
    exampleSet1();
    exampleSet2();
}