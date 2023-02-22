/*顺序容器：
  几个容器的创建：诸如vector，list,deque,set,map等*/
#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<string>
using namespace std;
// int main()
// {
	// vector<int> obv;
	// cout<<"obv的元素个数是："<<obv.size()<<endl;
	
	// double sz[5]={1,2,3,4,5};
	// deque<double> obd(sz,sz+5);
	
	// for(unsigned i = 0;i<obd.size();++i)//下标的访问方式！
	// {
		// cout<<obd[i]<<" ";
		
	// }
	// cout<<endl;
	
	// list<float> obl(3,5);
	// // list<float>::iterator iter=obl.begin();
	// auto iter = obl.begin();//这个也是可以的！遍历list
	// while(iter!=obl.end())
	// {
		// cout<<(*iter)<<" ";
		// iter++;
	// }
	// cout<<endl;
	// return 0;
// }


/*vector容器的插入和删除
  push_back,pop_back*/
  
// #include<iostream>
// #include<vector>
// using namespace std;

// int main()
// {
	// vector<int> v1(3,1);//初始化
	
	// v1.push_back(5);//进
	// for(unsigned int i = 0;i<v1.size();++i)
	// {
		// cout<<v1[i]<<" ";
	// }
	// cout<<endl;
	// v1.pop_back();
	// for(unsigned int i = 0;i<v1.size();++i)
	// {
		// cout<<v1[i]<<" ";
	// }
	// cout<<endl;
	// return 0;
// }


/*list容器的头部插入和头部删除操作！！不适合于vector
  push_front 和 pop_front*/
// #include<iostream>
// #include<list>

// using namespace std;

// int main()
// {
	// int sz[5]={1,2,3,4,5};
	// list<int> l1(sz,sz+5);
	// l1.push_front(6);
	// list<int>::iterator iter = l1.begin();
	// while(iter!=l1.end())
	// {
		// cout<<*iter<<" ";
		// iter++;
	// }
	// cout<<endl;
	
	// l1.pop_front();
	// iter = l1.begin();
	// while(iter!=l1.end())
	// {
		// cout<<*iter<<" ";
		// iter++;
	// }
	// cout<<endl;
	// return 0;

// }

/*读取头部和尾部的元素*/
//push_back 和 pop_back以及 push_front pop_front都是没有返回值
//你不知道删除和插入的返回值是什么！front 和 back可以读取序列最前端和尾端的元素
//但是只能读取，不能修改元素

// #include<iostream>
// #include<deque>
// using namespace std;

// int main()
// {
	// deque<int> d1 ={1,2,3,4,5};
	// cout<<d1.front()<<endl;
	// cout<<d1.back()<<endl;
	
	// return 0;
// }

/*插入操作*/

// #include<iostream>
// #include<vector>
// using namespace std;

// void disp(vector<int> &v)
// {
	// for(auto i:v)
		// cout<<i<<" ";
// }

// int main()
// {
	// vector<int> v1(5,0);//初始化5个0；
	// vector<int>::iterator iter = v1.end();
	// iter = v1.insert(iter,1);//在末尾插入1,返回的是新的末尾位置
	// disp(v1);
	// cout<<endl;
	// v1.insert(iter,2,3);//在末尾插入两个3
	// disp(v1);
	// cout<<endl;
	// iter = v1.begin();
	// int sz[3] = {1,2,3};//在开头插入数组
	// // v1.insert(iter,sz,sz+3);
	// v1.insert(iter,sz,sz+3);
	// disp(v1);
	// cout<<endl;
	// return 0;
// }


/*删除操作;erase操作*/
// #include<iostream>
// #include<list>
// using namespace std;
// void disp(list<int> &v)
// {
	// for(auto i:v)
		// cout<<i<<" ";
// }

// int main()
// {
	// int sz[7] = {1,2,3,4,5,6,7};
	// list<int> v1(sz,sz+7);//初始化5个0；
	// disp(v1);
	// cout<<endl;
	// list<int>::iterator iter = v1.begin();
	// iter++;
	// iter = v1.erase(iter);//删除第二个元素
	// disp(v1);
	// cout<<endl;
	// v1.erase(iter,v1.end());//删除除第一个以外的其余所有元素
	// disp(v1);
	// cout<<endl;
	// return 0;	
	
// }

/*----------------------------- 关联容器 --------------------------*/
/*关联容器有set，multiset，map，multimap，
  还有关联容器的插入，删除，查找，访问等*/


/*例题一：关联容器的集合set创建方式，只有键，没有值*/

// #include<iostream>
// #include<set>
// using namespace std;

// int main()
// {
	// int sz[9]={1,2,3,4,5,6,7,8,8};//不能出现相同的元素，最后只输出一个8！
	// set<int> s1(sz,sz+9);
	// set<int> ::iterator iter = s1.begin();
	
	// for(auto i:s1)
		// cout<<i<<" ";
	// cout<<endl;
	
	// while(iter!=s1.end())
	// {
		// cout<<*iter++<<" ";
	
	// }
	
	// cout<<endl;
	// return 0;
// }

/*例题二：multiset容器，允许出现相同的元素*/

// #include<iostream>
// #include<set>
// using namespace std;

// int main()
// {
	// int sz[9]={1,2,3,4,5,6,7,8,8};//不能出现相同的元素，最后只输出一个8！
	// multiset<int> s1(sz,sz+9);
	// multiset<int> ::iterator iter = s1.begin();
	
	// for(auto i:s1)
		// cout<<i<<" ";
	// cout<<endl;
	
	// while(iter!=s1.end())
	// {
		// cout<<*iter++<<" ";
	
	// }
	
	// cout<<endl;
	// return 0;
// }


/*例题三：map容器，类似于字典，唯一的一个键值！*/

// #include<iostream>
// #include<map>
// #include<string>

// using namespace std;

// int main()
// {
	// pair<int,string> sz [4] = {pair<int,string> (1,"hello"),pair<int,string> (2,"world"),
	// pair<int,string> (3,"are"),pair<int,string> (1,"you")};
	// map<int,string> m1(sz,sz+4);
	// cout<<m1.size()<<endl;
	// map<int,string> ::iterator iter = m1.begin();
	// while(iter!=m1.end())
	// {
		// cout<<(*iter).first<<" :"<<(*iter).second<<" ";
		// iter++;
	// }
	// cout<<endl;
	// return 0;
// }



/*例题四：multimap容器，类似于字典，键值不唯一！可以有多个键值对*/
// #include<iostream>
// #include<map>
// #include<string>
// using namespace std;
// int main()
// {
	// pair<int,string> sz [4] = {pair<int,string> (1,"hello"),pair<int,string> (2,"world"),
	// pair<int,string> (3,"are"),pair<int,string> (1,"you")};
	// multimap<int,string> m1(sz,sz+4);
	// cout<<m1.size()<<endl;
	// multimap<int,string> ::iterator iter = m1.begin();
	// //两种遍历方式：迭代器
	// // while(iter!=m1.end())
	// // {
		// // cout<<(*iter).first<<" :"<<(*iter).second<<" ";
		// // iter++;
	// // }
	// // cout<<endl;
	// //第二种遍历方式，auto的方式
	// for(auto i:m1)
		// cout<<i.first<<": "<<i.second<<endl;
	// return 0;
// }
/*关联容器的插入，删除操作*/
// #include<iostream>
// #include<map>
// #include<string>
// using namespace std;

// int main()
// {
	// pair<int,string> sz[2]={pair<int,string> (1,"hello"),
	// pair<int,string> (2,"world")};
	// pair<int,string> t(2,"x");//待插入的对象；
	// map<int,string> m1(sz,sz+2);
	// map<int,string> ::iterator iter = m1.begin();
	// pair<map<int,string>::iterator,bool> res = m1.insert(t);
	// if(res.second)
	// {
		// cout<<"success"<<endl;
	// }
	// else
		// cout<<"包含关键字相同的元素："<<(*res.first).second<<endl;
	// multimap<int,string> m2(sz,sz+2);
	// multimap<int,string>::iterator iter1 = m2.begin();
	// iter1 = m2.insert(t);
	// cout<<"success"<<" "<<(*iter1).second<<endl;
	// return 0;
// }
 
 
int main()
{
	string a = "helloname";
	a.replace(2, 3, "world");
	char chara = 'a';
	int intb = (int)chara;
	cout<<intb<<endl;
	char x = 1 + '0';
	cout<<"x "<<x<<endl;
	cout<<a<<endl;
} 
















































