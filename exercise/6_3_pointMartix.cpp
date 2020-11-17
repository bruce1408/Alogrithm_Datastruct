#include<iostream>
#include<string>
using namespace std;

/**
 * 指针数组，存的都是指针。
 * 而指向数组的指针是另外一回事，第一个例子是指针数组
 * 第二个例子是指针指向一个数组。
 * */
void pointer_array_1()
{
	int lin1[] = {1,0,0};
	int lin2[] = {0,1,0};
	int lin3[] = {0,0,1};
	
	
	int* pline[] = {lin1, lin2, lin3};  // 指针数组，保存的都是指针
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			cout<<pline[i][j]<<" ";
		cout<<endl;
	}
	
	//指向数组的指针；
	cout<<endl;
	int b[] = {0, 1, 2, 3, 4, 5};
	int *p = b;
	for (int i =0; i!=6; ++i)
		cout<<*(p+i)<<" ";
    cout<<endl;
}

/*这个例题对于理解数组指针和指针数组来说很重要*/
void pointer_array_2()
{
    int m[3][5]=
    {
        14,13,12,
        11,10,9,
        8,7,6,
        5,4,3,
        2,1,0
    };

    int (*p)[5];//数组指针,理解为指向数组的指针，指向一维数组,亦称行指针，
	            //每个一维数组有[n]个元素
				//其中n值要求与二维数组的列一致
    int i,j;
    int *q[3];//指针数组， q是数组，数组元素是指针，3个int指针，记住行首地址即可

    p=m;		//p是指针，可以直接指向二维数组
    cout<<"====== 1、数组指针第一种遍历方式：======\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<5;j++) 
        {
            cout<<*((*p+i)+j)<<" ";    //这种不可以，他是列的形式
            // cout<<*(*(p+i)+j)<<" ";    //注意元素值的取值方式
            // cout<<p[i][j]<<" ";    //注意元素值的取值方式
        }
        cout<<"\n";
    }
    cout<<"\n====== 2、数组指针的第二种遍历方式:======\n";
    for(i=0;i<3;i++,p++)				//p可看成是行指针,取值方式类似*(*(p+i)+j))
    {
        cout<<"*(p+1): "<<*(p+1)<<endl;	
		cout<<"**(p+1): "<<**(p+1)<<"\n";		
        cout<<"*p+1: "<<*p+1<<"\n";				
        cout<<"*(p*+1): "<<*(*p+1)<<"\n";				
        // cout<<*p+2<<" ";				//每一行的第一个元素
        // cout<<*p+3<<" ";				//每一行的第一个元素
        // cout<<*p+4<<" ";				//每一行的第一个元素
        // cout<<*(*p+1)<<" ";			//每一行的第二个元素
        // cout<<*(*p+2)<<" ";			//每一行的第三个元素
        // cout<<*(*p+3)<<" ";			//每一行的第四个元素
		// cout<<*(*p+4)<<" ";			//每一行的第四个元素
        cout<<"\n";
    }

	cout<<"\n====== 3、数组指针的第三种遍历方式：======\n";
	// cout<<*(*(p+i)+j)<<" "，以下代码很好的反映了*(p+1)和(*p+1)之间的区别，
	//p直接就是行指针，*p+1其实是对应的是列的地址；
	for(int (*p1)[5]=m;p1!=m+3;p1++)  
	{	for(int *q1 = *p1;q1!=(*p1)+5;q1++)
			cout<<*q1<<" ";
		cout<<endl;
	}
	
   
   
   
    cout<<"\n====== 4、最常见的遍历方式[i][j]:======\n";
	//q是数组,里面的元素是指针即，元素q[i]是指针。
	//初始化时将每个元素（指针）
	//指向数组a每行元素的首地址即可
    for(i=0;i<3;i++)
        q[i]=m[i];	
    for(i=0;i<3;i++)
    {
        for(j=0;j<5;j++)
        {
            cout<<q[i][j]<<" ";	//q[i][j]可换成*(q[i]+j)
        }
        cout<<"\n";
    }
    cout<<"\n====== 第二种遍历方式：======\n";

    // q[0]=m[0];			//记住第一行元素的首地址
    *q=m[0];			//记住第一行元素的首地址
    for(i=0;i<3;i++)
    {
        for(j=0;j<5;j++)
        {
            cout<<*(q[0]+5*i+j)<<" ";//首地址+第i行第j列元素的址，再取值即可
        }
        cout<<"\n";
    }
    cout<<"\n";
}




/**
 * 3-11
 * a既是数据名，又是指向数组第一个元素的指针。sizeof(a)=20, 此时a的类型为int[5]数组。
 * sizeof(*a)=4，因为有取值符*，表示把a当成一个指针(int*)，而a指向数组的首地址，
 * 即a=&(a[0])，即sizeof(*a)=sizeof(*&(a[0]))=sizeof(a[0])=sizeof(int)=4。
 * *(a+1)中把a当成一个指针，a+1=a+sizeof(int)，a+1指向a的下一个整形地址既&a[1]。
 * 因此*(a+1)=*(&a[1])=a[1]=2。
 * (&a+1)先取变量a的地址，并根据a的地址获得下一个与a同类型的相邻地址。根据前面所说的a的类型为int[5]数组。
 * &a+1=&a+sizeof(5*int)，因此&a+1指向的地址为&a[5](数组a[5]的下一个地址)。
 * (int*)(&a+1)把这个相邻地址显式类型转换为int类型的地址int*ptr=(int*)(&a+1);
 * 所以ptr指向&a[5]，并且ptr是一个int类型的指针。
 * ptr-1=ptr-sizeof(int)，故ptr-1指向&a[4]。因此，*(ptr-1)的值即为a[4]=5
 * */

void pointer_array_3()
{
	int a[5] = {1,2,3,4,5};
	int *pt =(int*)(&a+1);
	cout<<"*(a) : "<<*(a)<<endl;
	cout<<"*(a+1) : "<<*(a+1)<<endl;
	cout<<*(pt-1)<<endl;
	cout<<"首元素指针大小： "<<sizeof(*a)<<endl;
	cout<<"整个数组的大小： "<<sizeof(a)<<endl;
	
}

/**
 * 3-12 指针同时指向该字符数组，才会相同
*/

void pointer_array_4()
{
	char str1[] = "abc";
	char str2[] = "abc";
	const char str3[] = "abc";
	const char str4[] = "abc";
	const char* str5 = "abc";
	const char* str6 = "abc";
	
	cout<<"str1 == str2 ?: "<<(str1==str2)<<endl;
	cout<<"str3 == str4 ?: "<<(str3==str4)<<endl;
	cout<<(str5==str6)<<endl;
}



int main()
{
	pointer_array_1();
	pointer_array_2();
    pointer_array_3();
    pointer_array_4();
}
































































