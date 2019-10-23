// #include<iostream>
// #include<set>
// using namespace std;

// int main()
// {
// 	set<int> s1;
// 	int a[]={1,5,4,9,0};
// 	set<int>s2(a,a+5);
// 	set<int>s3(s2);
// 	set<int>::iterator it;
// 	set<int>::reverse_iterator rit;
// 	cout<<"集合中的元素是："<<endl;
// 	for(it=s2.begin();it!=s2.end();it++)
// 		cout<<*it<<" ";
// 	cout<<endl;
// 	// for(rit = s3.rbegin();rit!=s3.rend();rit++)
// 		// cout<<" "<<*rit;
	
// 	while(!s2.empty())
// 	{
// 		cout<<*s2.begin()<<" ";
// 		s2.erase(s2.begin());
// 	}
	
// 	cout<<s2.max_size();//集合最大可以容纳的元素个数：
	
	
// 	set<int> myset;
// 	set<int>::iterator it;
// 	pair<set<int>::iterator,bool> ret;

// 	// set some initial values:
// 	for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

// 	ret = myset.insert(20);               // no new element inserted

// 	if (ret.second==false) it=ret.first;  // "it" now points to element 20

// 	myset.insert (it,25);                 // max efficiency inserting
// 	myset.insert (it,24);                 // max efficiency inserting
// 	myset.insert (it,26);                 // no max efficiency inserting

// 	int myints[]= {5,10,15};              // 10 already in set, not inserted
// 	myset.insert (myints,myints+3);
	
// 	myset.insert (25);                 // max efficiency inserting
// 	myset.insert (24);                 // max efficiency inserting
// 	myset.insert (26); 
// 	cout << "myset contains:";
// 	for (it=myset.begin(); it!=myset.end(); ++it)
// 	cout << ' ' << *it;
// 	cout << '\n';
// }


// #include <iostream>
// #include <string>
// #include <unordered_map>
// using namespace std;

// int main ()
// {
//   unordered_map<string,double> mymap = {
//      {"mom",5.4},
//      {"dad",6.1},
//      {"bro",5.9} };

//   string input;
//   cout << "who? ";
//   getline (cin,input);

//   unordered_map<string,double>::const_iterator got = mymap.find (input);

//   if ( got == mymap.end() )
//     cout << "not found";
//   else
//     cout << got->first << " is " << got->second;
//   cout << endl;
//   return 0;
// }

/**
 * multimap 不支持下标操作，所以不可以用下标来初始化赋值，而map支持下标赋值，可以用下标来初始化；
 * multimap我们遍历的时候使用迭代器来进行遍历即可；
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include<map>
#include<set>
using namespace std;

int main()
{

	multimap<int,int> mymap;
	for(int i=0;i<5;i++)
	{
		mymap.insert(pair<int, int>(i+3, i));
		// mymap[i] = i; // error no support index to assign the value;
	}

	// mymap.at("Mars") = 3396;
	// mymap.at("Saturn") += 272;
	// mymap.at("Jupiter") = mymap.at("Saturn") + 9638;

	// unordered_map 两种遍历方式；
	// for (auto& x: mymap) {
	// 	cout << x.first << ": " << x.second << endl;
	// }

	multimap<int, int>::iterator iterB = mymap.begin();
	multimap<int, int>::iterator iterE = mymap.end();
	while(iterB != iterE)
	{
		iterE--;
		// cout<<"the end is "<<iterE->first<<endl;
		
	}

	set<int>map_1;
	map_1.insert(2);
	map_1.insert(3);
	map_1.insert(1);
	map_1.insert(1);
	for(auto i:map_1)
	{
		cout<<i<<endl;
	}
	// for(unordered_map<string, int>::iterator iter = mymap.begin(); iter != mymap.end(); iter++)
	// {
	// 	cout<<iter->first<<endl;
	// }
	
	return 0;
}