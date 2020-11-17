/*函数的返回值是指针的话，该函数就是指针类型的函数。
  不能将非静态的局部地址用作函数的返回值。 
  还有数组指针 和 指针数组！
*/

//程序一：
// #include<iostream>
// using namespace std;

// int *serach(int *a,int num);

// int main()
// {
	
	// int array[10];
	// for (int i =0;i<10;i++)
		// array[i] = i;
	// int *p = serach(array,10);
	// cout<<*p<<endl;
	// return 0;

	
// }


// int *serach(int *a,int num)
// {
	// for(int i=0;i!=num;++i)
	// {	if(a[i]==5)
		// {	
			// return &a[i];
		// }
	
	// }
	
// }



// #include<iostream>
// using namespace std;

// int main()
// {
	
	// int sz[2][3][4]={{{1,2,3,4,},{5,6,7,8},{9,10,11,12}},{{13,14,15,16},{17,18,19,20},
	// {21,22,23,24}}};
	// int *pz = sz[0][0];
	// for(int i=0;i<2;i++)
		// for(int j=0;j<3;j++)
			// for(int k=0;k<4;k++)
				// cout<<*(pz+3*4*i+4*j+k)<<" ";

	// cout<<endl;
	// return 0;
// }


// test1.cpp : 定义控制台应用程序的入口点。
//最简单的辨别方式就是看函数名前面的指针号"*"有没有被括号（）包含，
//如果被包含就是函数指针，反之则是指针函数。



/* --------------------------- 指针作为函数的参数的应用 ----------------------*/

/*静态数组是没有办法去返回在另外一个函数创建的指针的，因为在A中创建这个数组，而在
  B中去调用，那么就算是指针去访问，也会出错，因为代码块随着括号消失，内存中的数也消失
  这时候指针没有办法，可以解决的方法有2，一是用static来做，二是用new创建一个动态数组，
  这样可以保证动态数组跨函数运行，记得还要进行对应的指针delete 来删除数组。*/ 
//int *&a

/*以下两个代码实质是一样的其实,用new来生成动态数组，定义一个新的函数来引用它*/
/*代码块1*/
// #include<iostream>
// using namespace std;
// int * fun(int *a ,int m)//代表的是整型指针类型的引用。
// {
	// a = new int[m];
	// // int p1[m];
	// int *p = a;
	// for(int i=0;i<m;i++)
		// *a++=i*i+1;
	// return p;
	
// }

// int main()
// {
	// int *b,n=5;
	// int *c=0;
	// c = fun(b,5);
	// for(int i=0;i<n;i++)
		// cout<<*c++<<" ";
	// cout<<endl;
	// delete []b;
	// return 0;
// }



/*代码块2*/
// #include<iostream>
// using namespace std;
// int *staticArr(int *a)
// {
	// // int pz[5] = {1, 2, 3, 4, 5};
	// a = new int[5];
	// // for(int i=0;i<5;)
	// int *pz = a;
	// a[0] = 0;
	// a[1] = 1;
	// a[2] = 2;
	// a[3] = 3;
	// a[4] = 4;
	
	// return a;
// }

// int main()
// {
	// int *pArr = 0;
	// int *b = 0;
	// pArr = staticArr(b);
	// for(int i=0;i<5;i++)
	// {
		// cout<<*pArr++<<" "; //这里能访问到staticArr创建的静态数组
	// }
	
	// delete b;
	// b = nullptr;
	// return 0;
	
// }

/*int *&a
  代码块3稍有不同，因为代码块3的内容是没有返回指针的，这个时候怎么办？这个时候我们用
  引用，只不过是指针类型的引用！*/

#include<iostream>
using namespace std;
void fun(int *&a ,int m)//代表的是整型指针类型的引用。
{
	a = new int[m];
	int *p = a;
	for(int i=0;i<m;i++)
		*p++=i*i+1;
}


int main()
{
	int *b,n=5;
	// int *c=0;
	fun(b,5);
	for(int i=0;i<n;i++)
		cout<<*b++<<" ";
	cout<<endl;
	delete []b;
	return 0;
}


//函数指针，指向函数的指针
#include<iostream>
using namespace std;

int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int (*p)(int,int);
	p = max;
	cout<< "the max num is: "<<p(3, 2)<<endl;
}






























































