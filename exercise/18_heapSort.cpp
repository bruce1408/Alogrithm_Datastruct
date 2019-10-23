// #include<iostream>
// #include<vector>
// using namespace std;

// /**
//  * 方法 1，构建最大堆，利用数组来存放堆,
//  * 堆的最主要的问题就是
//  * --插入元素 --删除最大元素
//  */
// // vector<int>buildHeap(vector<int>res)
// // {

// // }

// /**
//  * swim方法，最大堆的构建方式；
//  * 由下至上，对元素进行上浮，因为堆的某个元素比它的父节点还要大，
//  * 我们需要交换它和它的父节点来修复堆，
//  * 交换之后，这个节点可能比父节点还要大，为了满足条件，要遍历；
// */
// void swim(vector<int>& res, int k)
// {
//     while(k>1 && res[k/2]<res[k])
//     {
//         swap(res[k/2], res[k]);
//         k = k/2;
//     }
// }

// /**
//  * sink方法，最大堆的构建方式；
//  * 由下至上构建这个二插堆，
//  * 因为某个节点比它的子节点还要小，通过和子节点中较大的那个来交换，然后恢复堆；
//  * 这一步做完之后，我们还要继续比较子节点交换之后是不是不满足条件；
// */
// void sink(vector<int>&res, int k)
// {
//     int N = res.size();
//     while(2*k < N)
//     {
//         int j = 2*k;
//         if(j<N && res[j]<res[j+1]) j++;
//         if(res[k]>=res[j]) break;
//         swap(res[j], res[k]);
//         k = j;
//     }
// }

// /**
//  * 方法 2，构建一个最小堆的数组
// */
// void swimMin(vector<int>& res, int k)
// {
//     while(k>1 && res[k/2]>res[k])
//     {
//         swap(res[k/2], res[k]);
//         k = k/2;
//     }
// }

// void sinkMin(vector<int>&res, int k)
// {
//     int N = res.size();
//     while(2*k < N)
//     {
//         int j = 2*k;
//         if(j<N && res[j]>res[j+1]) j++;
//         if(res[k]<=res[j]) break;
//         swap(res[j], res[k]);
//         k = j;
//     }
// }

// void exah(vector<int>&res, int a, int b)
// {
//     int temp = res[a];
//     res[a] = res[b];
//     res[b] = temp;
// }

// int main()
// {
//     vector<int>res = {0,50,10,90,30,70,40,80,60,20};
//     for(int i=1;i<res.size();i++)
//     {
//         sinkMin(res, i);
//     }
//     for(auto i:res)
//     {
//         cout<<i<<" ";
//     }
//     cout<<endl;
//     int N = res.size();
//     while(N>1)
//     {
        
//         // exah(res, 1, N-1);
//         swap(res[1], res[N-1]);
//         for(auto i:res)
//         {cout<<i<<" ";}
//         cout<<endl;
//         cout<<"the min num is:"<<res[N-1]<<" "<<endl;
//         res.pop_back();
//         N--;
//         sinkMin(res, 1);
//     }

// }


#include<iostream>
#include<vector>
using namespace std;

/**
 * maxHeap
*/
template<class type>
void heapAdjust(vector<type>& vec, int index, int length)
{
    int i = index;
    int j = 2*i;
    for(; j<=length; j*=2)
    {
        if(j+1<=length && vec[j]<vec[j+1]) j++;
        if(vec[i]>vec[j]) break;
        swap(vec[i], vec[j]);
        i = j;
    }
}

template<class type>
void heapSort(vector<type>&vec)
{
    int length = vec.size();
    for(int i=(length-1)>>1;i>=1;i--)
    {
        heapAdjust(vec, i, length-1);
    }
    
    for(int i=length-1;i>1;i--)
    {
        type temp = vec[1];
        vec[1] = vec[i];
        vec[i] = temp;
        heapAdjust(vec, 1, i-1);
    }
}

int main()
{
    vector<int>res = {0,50,10,90,30,70,40,80,60,20};
    heapSort(res);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}



// #include<vector>
// #include<iostream>
 
// using namespace std;
 
// template<class type>
// void heapAdjust(vector<type>& vec,int index,int length)
// {//堆排序的核心算法：堆调整
// 	int i=index;
// 	int j=2*i;
 
// 	for(;j<=length;j=j*2)
// 	{
// 		if(j+1<=length && vec[j]<vec[j+1])
// 			j++;//使j指向较大值
// 		if(vec[i]>vec[j])
// 			break;
// 		else
// 		{//使较大值上浮
// 			type tmp=vec[i];
// 			vec[i]=vec[j];
// 			vec[j]=tmp;
// 			i=j;
// 		}
// 	}
// }
 
// template<class type>
// void heapSort(vector<type>& vec)
// {
// 	int length=vec.size();
// 	for(int i=(length-1)>>1;i>=1;--i)
// 	{//建堆的过程是一个上浮的过程，从底层逐层上浮
// 		heapAdjust(vec,i,length-1);
// 	}
 
// 	for(int i=length-1;i>1;--i)
// 	{//出堆过程是一个下沉的过程，从堆底一直沉到底部
// 		type tmp=vec[1];
// 		vec[1]=vec[i];
// 		vec[i]=tmp;
// 		heapAdjust(vec,1,i-1);
// 	}
// }
 
// int main()
// {
// 	int a[11]={0,1,4,8,5,9,6,3,0,2,7};
// 	vector<int> vec(a,a+11);
 
// 	heapSort(vec);
 
// 	for(int i=1;i<vec.size();++i)
// 	{
// 		cout<<vec[i]<<"   ";
// 	}
// 	cout<<endl;
 
// 	return 0;
// }
