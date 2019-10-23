/*结构体和联合体的用法：
  结构体是一种类，默认的是public类型，类的成员默认的是private
  结构体允许整体复制，但是数组不允许整体复制，所以定义的时候可以
  在结构体里面对结构体复制，这样数组就能复制了。
  联合体各种数据类型共占一个同一个内存地址*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;




//例子一
// struct Student{
	// int num;
	// string name;
	// char sex;
	// int age;
	
	
// }stu2 = {1999,"hell",'m',80};// 两种初始化的方法。


// int main()
// {
	// Student stu = {1970,"bruce",'f',19};
	// cout<<stu.num<<endl;
	// cout<<stu.name<<endl;
	// cout<<stu.sex<<endl;
	// cout<<stu.age<<endl;
	
	// cout<<stu2.num<<endl;
	// cout<<stu2.name<<endl;
	// cout<<stu2.sex<<endl;
	// cout<<stu2.age<<endl;
	
	// return 0;
		
// }





//例子二
// struct comst1
// {
	
	// char brand[10];
	// float price;
// };

// union comst2
// {
	// char brand[10];
	// float price;
// };


// int main()
// {
	
	
	// comst1 com1;
	// comst2 com2;
	// cout<<&com1.brand<<endl;
	// cout<<&com1.price<<endl;
	// cout<<&com2.brand<<endl;//地址都一样
	// cout<<&com2.price<<endl;//地址都是一样的
	
	
	// return 0;
	
// }


/*联合体的例子*/
// union info
// {
	// int grade;
	// char department[20];
// };


// int main()
// {
	// info inputinfo;
	// int i = -1;
	// cout<<"老师还是学生？0代表学生，1代表老师"<<endl;
	// cin>>i;
	// if(i ==0)
	// {
		// cout<<"学生身份登录操作："<<endl;
		
		// cin>>inputinfo.grade ;
		// cout<<"你所在的年级是："<<inputinfo.grade;
			
		
	// }
	// else
	// {
		// cout<<"老师身份登录："<<endl;
		
		// cin>>inputinfo.department;
		// cout<<"你所在的部分是: "<<inputinfo.department<<endl;
	// }
	

	// return 0;
	
// }


/*结构体数组，下标或者是解引用来访问对应的元素*/

// struct student
// {
	// char name[20];
	// int age;
	// float weight;
// };


// int main()
// {
	// student* p = new student[5];
	// cout<<"请以此输入名字，年龄，体重："<<endl;
	// cin>>(*(p+2)).name;
	// cin>>(*(p+2)).age;
	// cin>>(*(p+2)).weight;
	// cout<<endl;
	// cout<<(*(p+2)).name<<endl;// 稍微麻烦，但是清楚
	// cout<<p[2].age<<endl;//这种下标的方式也可以写！
	// cout<<p[2].weight<<endl;
	// // cout<<p[2]->weight<<endl;//这种方法好像不行。
	
	// delete[] p; //记得释放内存
	// return 0;
	
// }


/*结构体，指针箭头访问对应的元素->,但是对于结构体数组好像此方法不行*/

// struct student
// {
	// char name[20];
	// int age;
	// float weight;
// };


// int main()
// {
	// student* p = new student;
	// cout<<"请以此输入名字，年龄，体重："<<endl;
	// cin>>(*p).name;
	// cin>>(*p).age;
	// cin>>(*p).weight;
	// cout<<endl;
	// cout<<(*p).name<<endl;// 稍微麻烦，但是清楚
	// cout<<(*p).age<<endl;//这种下标的方式也可以写！
	// cout<<p->weight<<endl;
	// // cout<<p[2]->weight<<endl;//这种方法好像不行。
	
	// delete p; //记得释放内存

	// return 0;
	
// }

/*结构体和typedef类型的配合使用！*/


//1
typedef struct node
{
    struct node *lchild;
    struct node *rchild;
    char data;
}BiTreeNode, *BiTree;


void createBiTree(BiTree &T) 
//&的意思是传进来节点指针的引用，括号内等价于 BiTreeNode* &T,
//目的是让传递进来的指针发生改变
{
	char c;
	cin >> c;
    if('#' == c)             
		//当遇到#时，令树的根节点为NULL，从而结束该分支的递归
        T = NULL;
    else
    {
        T = new BiTreeNode;// 新建一个节点，
        T->data=c;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
}

//2
struct Student
{
	int a;
	
}stu1;

//3
typedef struct Student2
{
	int b;
}stu2,stu3,*stu4;


void creatStudent(stu4 &T)
{
	int num;
	cin>>num;
	if(num == 0)
		T = NULL;
	else
	{
		T = new stu3;
		T->b = 11;
	}
	cout<<"t.b = "<<T->b<<endl;
}




int main()
{
	// stu1.a = 10;
	// cout<<stu1.a<<endl;
	// stu2 ns;
	// ns.b = 9;
	// cout<<ns.b<<endl;
	int num  = 12;
	stu2 s2; 
	s2.b = 14;
	stu3 s3;
	stu4 s4;
	// s2.b = 10;
	s3.b = 11;
	s4->b = 12;
	cout<<"s2.b = "<<s2.b<<endl;
	cout<<"s3.b = "<<s3.b<<endl;
	cout<<"s4.b = "<<s4->b<<endl;
	
	
	stu4 em = &s3;
	em->b = 90;
	creatStudent(em);
	cout<<"em.b = "<<em->b<<endl;
	
	// int *a = new int;
	// int *b = new int ;
	// *a = 10;
	// *b = 11;
	// cout<<*a<<endl;
	// cout<<*b<<endl;
	// delete a;
	// delete b;
	// a = nullptr;
	// b = nullptr;
	
	return 0;
}






















































