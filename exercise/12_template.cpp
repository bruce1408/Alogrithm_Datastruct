/*模板
  模板分为函数模板和类模板两种；它不是实实在在的函数或者是类，仅仅是函数或者类的描述
  模板运算类型不是实际的数据类型，而是参数化的类型，称为类属类型。*/

//例子1
// #include<iostream>
// using namespace std;
// template <class T>
// T abs(T x)
// {
// 	return (x>0?x:-x);
// }
// int main()
// {
// 	cout<<abs(-9)<<endl;
// 	cout<<abs(-9.3)<<endl;
// 	return 0;
// }
 

// 例子2
// #include<iostream>
// #include<string>
// using namespace std;

// template<class T>
// T add(const T &t1, const T &t2)
// {
// 	return t1+t2;
// }


// int main()
// {
// 	int a = 1,b = 2;
// 	string s1("hello,"),s2("world");
// 	cout<<add(a,b)<<endl;
// 	cout<<add(2.1,2.8)<<endl;
// 	cout<<add(s1,s2)<<endl;
// 	return 0;
// }



/*函数模板分：隐式实例化、显示实例化！*/
/*例题一：*///隐式实例化.隐式实例化是在函数调用的时候才能决定他的类型参数

// #include<iostream>
// using namespace std;
// // 模板类的声明
// template<class Ex>
// Ex creater(Ex x, Ex y);

// int main()
// {
	// int x = 1,y = 2;
	// double d1 = 0.8,d2 = 0.4;
	// cout<<creater(x,y)<<endl;
	// cout<<creater(d1,d2)<<endl;
	// return 0;
	
// }
// //实现
// template<class Ex>
// Ex creater(Ex x,Ex y)
// {
	// return x>y?x:y;
// }


/*例题二：*///显式实例化.显式实例化一般只出现一次，模板类型实参是已知的
// #include<iostream>
// using namespace std;

// template<class Ex>//模板的声明
// Ex creater(Ex x,Ex y);

// template int creater<int>(int,int);//显式实例化,不用再写实例化的定义

// int main()
// {
	// int x = 1,y = 3;
	// double d1 = 0.8, d2 = 0.6;
	
	// cout<<creater(x,y)<<endl;
	// cout<<creater(d1,d2)<<endl;
	// return 0;
// }

// template<class Ex>//模板的定义
// Ex creater(Ex x,Ex y)
// {
	// return x>y?x:y;
// }


/*例题三：*///特化.解决某些类型在函数中的特殊操作
// #include<iostream>
// using namespace std;

// template<class Ex>
// Ex creater(Ex x,Ex y);

// template<> double creater<double>(double,double);//特化

// int main()
// {
	// int x = 1,y = 13;
	// double d1 = 0.8, d2 = 10.6;
	
	// cout<<creater(x,y)<<endl;
	// cout<<creater(d1,d2)<<endl;
	// return 0;
// }

// template<class Ex>
// Ex creater(Ex x,Ex y)
// {
	// return x>y?x:y;
// }

// //特化定义部分
// template<> double creater<double>(double x,double y)
// {
	
	// return x+y;
	
// }


/*类模板分：*/
// #include<iostream>
// // #include "Stack.h"
// using namespace std;



// template<class T,int num>
// class Stack
// {
// 	private:
// 	T sz[num];
// 	int point;
// 	public:
// 	Stack();
// 	bool isFull();
// 	bool isEmpty();
// 	bool push(const T&);
// 	bool pop(T&);
// };

// template<class T,int num>
// Stack<T,num>::Stack()
// {
// 	point = 0;
// }

// template<class T,int num>
// bool Stack<T,num>::isEmpty()
// {
// 	return point == 0;
// }

// template<class T,int num>
// bool Stack<T,num>::isFull()
// {
// 	return point == num;
// }

// template<class T,int num>
// bool Stack<T,num>::push(const T &obt)
// {
// 	if(isFull())
// 		return false;
// 	else
// 	{
// 		sz[point]=obt;
// 		point++;
// 		return true;
		
// 	}
// }

// template<class T,int num>
// bool Stack<T,num>::pop(T & obt)
// {
// 	if(isEmpty())
// 		return false;
// 	else
// 	{
// 		point--;
// 		obt=sz[point];
// 		return true;
// 	}
// }





// int main()
// {
// 	Stack<int,10> st;
// 	cout<<"开始时st是否为空？ "<<st.isEmpty()<<endl;
// 	st.push(5);
// 	cout<<"此时的st是否是空？"<<st.isEmpty()<<endl;
// 	for(int i=1;i<10;i++)
// 	{
// 		st.push(i);
// 	}
	
// 	cout<<"st是否已经满了？"<<st.isFull()<<endl;
// 	int rec = 0;
// 	while(st.pop(rec))
// 		cout<<rec<<" ";
// 	cout<<endl;
// 	return 0;
	
	
// }

/*类模板：显式特化，例题一：*/

// #include<iostream>
// #include<cstring>
// using namespace std;
// template<class Ex>
// Ex Greater(Ex x,Ex y);
// template<> double Greater(double ,double);


// char *Greater(char *x ,char * y)
// {
	// cout<<"一般函数被执行"<<endl;
	// return(strcmp(x,y)>0)?x:y;
// }

// int main()
// {
	// int a = 10,b = 3;
	// double d1 = 10.8,d2 = 10.3;
	// cout<<Greater(a,b)<<endl;
	// cout<<Greater(d1,d2)<<endl;
	// cout<<Greater("world","hello")<<endl;
	// return 0;
// }


// template<class Ex>
// Ex Greater(Ex x,Ex y)
// {
	// return x>y?x:y;
// }

// template<> double Greater(double x,double y)
// {
	// return x+y;
// }

/* 例题4，设计一个类模板，二分法差查找有序数组的元素*/
// #include<iostream>
// using namespace std;
// const int Max = 100;
// template<class T>
// class Sample
// {
	// T A[Max];
	// int n;
	// public:
	// Sample(){}
	// Sample(T a[],int i);
	// int seek(T c);
	// void disp()
	// {
		// for(int i=0;i<n;i++)
		// {
			// cout<<A[i]<<" ";
		// }
		// cout<<endl;
	// }
// };

// template<class T>
// Sample<T>::Sample(T a[],int i)
// {
	// n = i;
	// for(int j=0;j<i;j++)
	// {
		// A[j]=a[j];
	// }
// }

// template <class T>
// int Sample<T>::seek(T c)
// {
	// int low = 0,high = n-1,mid;
	// while(low<=high)
	// {
		// mid = (low + high)/2;
		// if(A[mid]==c)
			// return mid;
		// else
			// if(A[mid]<c)
				// low = mid + 1;
			// else
				// high = mid - 1;
	// }
	// return -1;
// }

// int main()
// {
	// char a[]="acdgkmpwxy";
	// Sample<char>s(a,10);
	// cout<<"元素的序列：";s.disp();
	// cout<<"g的下标是："<<s.seek('g')<<endl;
	// return 0;
// }





















































