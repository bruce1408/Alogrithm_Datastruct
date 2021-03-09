/*自定义数据类型，有枚举、结构体、共同体
  其中枚举的数值从0开始计算，然后依次增1；*/
#include <iostream>
using namespace std;

//枚举
// int main()
// {
// enum week{sun,mon=20,tue,wen,thu,fri,sat};
// cout<<"输出枚举符号的数值。"<<endl;
// cout<<"sun="<<sun<<endl;
// cout<<"mon="<<mon<<endl;
// cout<<"tue="<<tue<<endl;
// cout<<"sun="<<wen<<endl;
// cout<<"wen="<<thu<<endl;
// cout<<"fri="<<fri<<endl;
// cout<<"sat="<<sat<<endl;
// week weekday = fri;
// cout<<"weekday="<<weekday<<"\n";
// return 0;
// }

//结构体数组

// #define studentNumOfPreClass 3
// #define maxNameLength 20

// struct Student
// {
// int number;
// char name[maxNameLength];
// float score;
// };

// Student ourclass[studentNumOfPreClass];

// void inputData()
// {
// for(int i = 0;i<studentNumOfPreClass;++i)
// {
// cout<<"请输入第 "<<i+1<<" 个学生的姓名"<<endl;
// cin>>ourclass[i].name;
// cout<<"请输入第 "<<i+1<<" 个学生的学号"<<endl;
// cin>>ourclass[i].number;
// cout<<"请输入第 "<<i+1<<" 个学生的成绩"<<endl;
// cin>>ourclass[i].score;

// }
// }

// void outputData()
// {
// for(int i=0;i<studentNumOfPreClass;++i)
// {
// cout<<"第 "<<i+1<<" 个学生的姓名；";
// cout<<ourclass[i].name<<endl;
// cout<<"第 "<<i+1<<" 个学生的学号；";
// cout<<ourclass[i].number<<endl;
// cout<<"第 "<<i+1<<" 个学生的成绩；";
// cout<<ourclass[i].score<<endl;
// }

// }

// int main()
// {
// inputData();
// cout<<'\n';
// outputData();
// return 0;
// }

/*这个程序非常好！利用了联合体union和结构体来构建一个员工信息表，程序写的非常精妙
  注意：union 的使用方法，在构造器里面怎么调用！这个很厉害
        while()函数的使用，break的使用技巧！！*/
void fucchoice();
void input();
void print();
// void query();

const int Maxt = 80, Maxs = 160;
int curT = 0, curS = 0;

struct Teacher
{
	int no;
	char name[20];
	char sex[3];
	//
	union
	{
		char post[15];
		char classn[21];
	} ts;
	//
	char dept[31];

} tec[Maxt], stu[Maxs];

// void update();

int main()
{

	int choice;
	while (1)
	{
		fucchoice();
		cout << "请根据界面提示输入需要的功能号：";
		cin >> choice;
		switch (choice)
		{
		case 1:
			input();
			break;
		// case 2:query();break;
		case 3:
			print();
			break;
		// case 4:update();break;
		case 0:
			break;
		}
		if (choice == 0)
			break;
	}
	cout << "欢迎下次继续使用该功能！" << endl;
	return 0;
}

void fucchoice()
{
	cout << "******************功能界面*******************" << endl;
	cout << "\t\t 1.输入功能。\t\t" << endl;
	cout << "\t\t 2.查询功能。\t\t" << endl;
	cout << "\t\t 3.打印功能。\t\t" << endl;
	cout << "\t\t 4.更新功能。\t\t" << endl;
	cout << "\t\t 0.退出功能。\t\t" << endl;
	cout << "***************功能界面*******************" << endl;
}

void input()
{
	int choice, i;
	char yes;
	while (1)
	{

		cout << "***************输入功能界面*******************" << endl;
		cout << "\t\t 11.输入教师信息。\t\t" << endl;
		cout << "\t\t 12.输入学生信息。\t\t" << endl;
		cout << "\t\t 0.返回主菜单。\t\t" << endl;
		cout << "***************输入功能界面*******************" << endl;
		cout << "请根据界面提示输入需要的功能号：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 11:
			while (1)
			{
				if (curT + 1 > Maxt)
				{
					cout << "空间已满，不需要再输入教师信息。";
					break;
				}

				else
				{
					cout << "请输入第 " << curT + 1 << " 个教师的信息：" << endl;
					cout << "输入功号：" << endl;
					cin >> tec[curT].no;
					cout << "输入姓名：" << endl;
					cin >> tec[curT].name;
					cout << "输入性别：";
					cin >> tec[curT].sex;
					cout << "输入班级：";
					cin >> tec[curT].ts.post;
					cout << "输入院系：";
					cin >> tec[curT].dept;
					curT++;
					cout << "是否输入下一个教师的信息：y:n?" << endl;
					cin >> yes;
					if (yes == 'y' || yes == 'Y')
					{
						continue;
					}
					else
						break;
				}
			}
			break;
		case 12:
			while (1)
			{
				if (curS + 1 > Maxs)
				{
					cout << "空间已满，不需要再输入学生信息。" << endl;
					break;
				}
				else
				{
					cout << "请输入第 " << curS + 1 << " 个学生的信息：";
					cout << "输入学号：" << endl;
					cin >> stu[curS].no;
					cout << "输入姓名：";
					cin >> stu[curS].name;
					cout << "输入性别：";
					cin >> stu[curS].sex;
					cout << "输入职称：" << endl;
					cin >> stu[curS].ts.classn;
					cout << "输入院系：";
					cin >> stu[curS].dept;
					curS++;
					cout << "是否输入下一个学生的信息：y:n?" << endl;
					cin >> yes;
					if (yes == 'y' || yes == 'Y')
					{
						continue;
					}
					else
						break;
				}
			}

			break;

		case 0:
			break;
		}

		if (choice == 0)
			break;
	}
}

void print()
{
	int choice, i;
	while (1)
	{
		cout << "***************打印功能界面*******************" << endl;
		cout << "\t\t 31.打印教师信息。\t\t" << endl;
		cout << "\t\t 32.打印学生信息。\t\t" << endl;
		cout << "\t\t 0.返回主菜单。\t\t" << endl;
		cout << "***************打印功能界面*******************" << endl;
		cin >> choice;
		switch (choice)
		{
		case 31:
			cout << "教师的信息：" << endl;
			for (int i = 0; i < curT; i++)
			{
				cout << "名字：" << tec[i].name << "功号：" << tec[i].no << tec[i].dept << tec[i].ts.post << endl;
			}
			break;
		case 32:
			cout << "学生信息：" << endl;
			for (int i = 0; i < curS; i++)
			{
				cout << stu[i].name << stu[i].no << stu[i].dept << stu[i].ts.classn << endl;
			}
			break;
		case 0:
			break;
		}
		if (choice == 0)
			break;
	}
}
