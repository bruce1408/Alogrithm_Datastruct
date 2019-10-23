// #include<iostream>
// using namespace std;

// class Rectangle
// {
	// public:
	// Rectangle(int x,int y){a = x;b = y;}
	// int area(){return a*b;}
	// void show();
	// // {
		// // cout<<"三角形的面积是："<<area()<<endl;
	// // }
	
	// private:
	// int a;
	// int b;
// };
// //接口的实现写在外面！
// void Rectangle::show()
// {
	// cout<<area()<<endl;
// }

// int main()
// {
	// int a=9,b=10;
	// Rectangle x(a,b);
	// x.area();
	// x.show();
	// return 0;
	
// }


//5

// #include<iostream>
// using namespace std;

// int main()
// {
	
	// double e = 1,sum = 0;
	// int n = 1;
	// int flag = 1;
	
	// while(e>0.0001)
	// {
		// e = 0.1/n;
		// sum += flag*e;
		// flag = -flag;
		// n++;
	// }
	
	// cout<<sum<<endl;
	// cout<<1.0/n<<endl;

	// return 0;
// }


// #include<iostream>
// using namespace std;

// class numinvs
// {
	// private:
	// int num;
	
	// public:
	// numinvs(int n)
	// {
		// num = n;
	// }
	
	// int invs()
	// {
		// int n=num,sum=0;
		
		// while(n)
		// {
			// sum = sum*10+n%10;
			// n = n/10;
			
		// }
		// return sum;
		
	// }
	
// };


// int main()
// {
	// int j = 321;
	// numinvs a(j);
	// cout<<a.invs()<<endl;
	// // cout<<x<<endl;
	
// }




// #include <iostream>
// #define start using namespace std; 
// int main() {
// #define end <<endl;}
// #define print cout<<


// start
// print"hello world!"
// end


// #include<iostream>
// #include<cmath>
// using namespace std;

// int main()
// {
	// // int a = 10,b=6,c=4;
	
	// // cout<<a%9<<endl;
	// // cout<<int(12.3)%4;
	// // a++,a = 7+b+c;
	// // cout<<a<<endl;
	// // c = sqrt(fabs(sin(90*180/3.14)));
	// // cout<<c<<endl;
	
	// // int k = 2,i = 2,m;
	// // m = (k+=i*=k++);
	// // cout<<m<<i<<endl;
	// // unsigned a = 32768;
	// // int b;
	// // b = a;
	// // cout<<b<<endl;
	
	// int a=6;
	// cout<<a++<<endl;
	// cout<<a++<<endl;
	// {
		// int a = 8;
		// cout<<++a<<endl;
		
	// }
	// cout<<a<<endl;
	
	// return 0;
// }





// #include<iostream>
// using namespace std;
// struct sqlist
// {
	// int r[4];
	// int length;
// };

// void print_array(sqlist *l);//函数声明
// // void swap(sqlist *l,int i,int j);



// void Msort(sqlist *l,sqlist *m)
// {
	// int i = 0;
	// int j = 0;
	// int index=0;
	// int num = l->length+m->length;
	// // int a[num] = {0};
	// int *a = new int[num];// 动态生成长度为某数的数组
	
	
	
	// while(i<l->length&&j<m->length)
	// {
	
		// if(l->r[i] <= m->r[j])
		// {
			// a[index++] = l->r[i++];
		// }
		// else
		// {
			// a[index++] = m->r[j++];
		// }
       
	// }
	
	// //如果A中还有剩余元素，直接复制到tmp中
	// while(i<l->length)
	// {
		// a[index++] = l->r[i++];
	// }
	// //如果B中还有剩余元素，直接复制到tmp中
	// while(j < m->length)
	// {
		// a[index++] = m->r[j++];
	// }
	
	// for(int v=0;v<num;v++)
		// cout<<a[v]<<" ";
	// cout<<endl;
// }



// int main()
// {
	// sqlist *l,*m;
	// sqlist p,q;
	
	// for(int i=0;i<4;i++)
		// p.r[i] = i+3;
	// l = &p;
	// for(int i=0;i<4;i++)
		// q.r[i] = i+4;
	// m = &q;
	
	// l->length = sizeof(l->r)/sizeof(l->r[0]);
	// m->length = sizeof(m->r)/sizeof(m->r[0]);

	
	// cout<<"排序之前的结果："<<endl;
	// print_array(l);
	// print_array(m);
	
	
	// Msort(l,m);
	
	
	// return 0;
// }


// void print_array(sqlist *l)                 //打印显示代码
// {
	// // n = l->length;
	// for (int i = 0;i<l->length;i++)
		// cout<<l->r[i]<<" ";
	// cout<<endl;
// }

// void swap(sqlist *l,int i,int j)
// {
	// int temp = l->r[i];
	// l->r[i] = l->r[j];
	// l->r[j] = temp;
// }





/*两个有序数组的排序，然后合并成为一个新的数组。*/ 
// #include<iostream>
// #include<vector>
// using namespace std;
// void Msort(int *a,int *b,int anum,int bnum)
// {
// 	int i = 0;
// 	int j = 0;
// 	int index=0;
// 	int num =anum+bnum;
// 	int *aa = new int[num];// 动态生成长度为某数的数组
	
	
// 	while(i<anum&&j<bnum)
// 	{
	
// 		if(a[i] <= b[j])
// 		{
// 			aa[index++] = a[i++];
// 		}
// 		else
// 		{
// 			aa[index++] = b[j++];
// 		}
        
        
       
// 	}
// 	//如果A中还有剩余元素，直接复制到aa中
// 	while(i<anum)
// 	{
// 		aa[index++] = a[i++];
//     }
//     //如果B中还有剩余元素，直接复制到aa中
// 	while(j<bnum)
// 	{
// 		aa[index++] = b[j++];
// 	}
	
// 	for(int v=0;v<num;v++)
// 		cout<<aa[v]<<" ";
// 	cout<<endl;
// }


//计算数组中最大的数是几位数
// int maxbit(int data[],int n)
// {
//     int d=1;
//     for(int i=0;i<n;i++)
//     {
//         int c=1;
//         int p=data[i];
//         while(p/10)
//         {
//             p=p/10;
//             c++;
//         }
//         if(c>d)
//             d=c;
//     }
//     return d;
// }




// int main()
// {
	// int a[] ={0,1,3,5,6,12,19,29,31};
	// int b[] ={2,4,5,8,9,11,24};
	// int anum = sizeof(a)/sizeof(a[0]);
	// int bnum = sizeof(b)/sizeof(b[0]);
	// cout<<anum<<endl;
	// cout<<bnum<<endl;
	// Msort(a,b,anum,bnum);
	
// 	int sumn[] = {4,4,5,6,12,34,564,1234,56789,8};
// 	vector<int> nums(10,0);
// 	int u=0;
// 	// for(int i=0;i<9;i++)
// 	// {
// 		// nums[sumn[i]%10]++;	
// 		// // cout<<sumn[i]%10<<" ";
// 	// }
	
// 	// cout<<maxbit(sumn,9)<<endl;
// 	RadixSort(nums,10);
// 	cout<<endl;
// 	for(auto i:nums)
// 		cout<<i<<" ";
// 	return 0;
// 	vector<int>res1 = {2,3,5,7,9, INT_MAX};
// 	vector<int>res2 = {4,5,7,10, INT_MAX};
// 	vector<int>temp(9);
// 	int i=0,j=0;
// 	// cout<<res2[4]<<endl;
// 	for(int k=0;k<9;k++)
// 	{
// 		if(res1[i]<res2[j]) temp[k] = res1[i++];
// 		else temp[k] = res2[j++];
// 	}

// 	for(auto i:temp)
// 	{
// 		cout<<i<<endl;
// 	}
// 	cout<<temp.size()<<endl;
	
// }


/*美团笔试题*/
// class Solution
// {
// 	public:
// 	int gcd_num(int a,int b)
// 	{
// 		int n = min(a,b);
// 		for(int i=n;i>=1;i--)
// 		{
// 			if(a%i==0 && b%i==0)
// 			{
// 				return i;
// 			}
// 		}
// 		return 1;
// 	}

// 	int A_vec_generator(int N,int n,int m,int p)
// 	{
// 		vector<int>res;
// 		res.push_back(N);
// 		int sumres=0;
// 		for(int i =0;i<N &&res.size()<N ;i++)
// 		{
// 			res.push_back((res.back()+153)%p);
// 		}
// 		vector<int>temp;
		
// 		for(int i=1;i<=n;i++)
// 		{
// 			for(int j=1;j<=m;j++)
// 				temp.push_back(gcd_num(i,j));	
// 		}
		
		
// 		for(int t=0;t<temp.size();t++)
// 		{
// 			sumres+=res[temp[t]-1];
// 			cout<<temp[t]<<" ";
// 		}
// 		return sumres;
		
// 	}
	
// };

// int gcd_num(int a,int b)
// {
// 	int n = min(a,b);
// 	for(int i=n;i>=1;i--)
// 	{
// 		if(a%i==0 && b%i==0)
// 		{
// 			return i;
// 		}
// 	}
// 	return 1;
// }

// int A_vec_generator(int N,int n,int m,int p)
// {
// 	vector<int>res;
// 	res.push_back(N);
// 	int sumres=0;
// 	for(int i =0;i<N &&res.size()<N ;i++)
// 	{
// 		res.push_back((res.back()+153)%p);
// 	}
// 	vector<int>temp;
	
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=m;j++)
// 			temp.push_back(gcd_num(i,j));	
// 	}
	
	
// 	for(int t=0;t<temp.size();t++)
// 	{
// 		sumres+=res[temp[t]-1];
// 		cout<<temp[t]<<" ";
// 	}
// 	return sumres;
	
// }




// int main()
// {
// 	vector<int>res;
// 	Solution ss;
// 	cout<<ss.A_vec_generator(10,2,2,10);
// 	// for(auto i:res)
// 		// cout<<i<<" ";
// 	// cout<<endl;
// 	// cout<<gcd(20,30);
// }

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>res = {1,2,3,4};
	swap(res[0], res[3]);
	res.pop_back();
	cout<<res.size()<<endl;
	for(auto i:res)
	{
		cout<<i<<" ";
	}
}








































































