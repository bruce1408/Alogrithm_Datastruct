/* 164 Maximum Gap,求解一组序列中两两之间差值最小的那个数。
   最简单的就是用sort函数，排序求最大的差值
   其他方法是可以用基数排序或者是桶排序！*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// void swap(vector<int>& nums,int low,int high)
// {
	// int temp = nums[low];
	// nums[low] = nums[high];
	// nums[high] = temp;
// }


// int partiton(vector<int> &nums,int low ,int high)
// {
	// int pivokey; 
	// pivokey = nums[low];
	// while(low<high)
	// {
		// while(low<high && nums[high]>=pivokey)
			// high--;
		// swap(nums,low,high);
		
		// while(low<high && nums[low]<=pivokey)
			// low++;
		// swap(nums,low,high);
	// }
	// return low;
// }


// void Quicksort(vector<int>& nums,int low,int high)
// {
	// int posit;//返回的是位置
	// while(low<high)
	// {
		// posit = partiton(nums,low,high);
		// Quicksort(nums,low,posit-1);
		// low = posit + 1;
	// }
// }


// /*第一种解法用了自己自带的sort或者是自己实现的函数，时间复杂度还是比较高的。*/
// class Solution 
// {
	// public:
    // int maximumGap(vector<int>& nums) 
	// {
		// // sort(nums.begin(),nums.end());
		// Quicksort(nums,0,nums.size()-1);
		// int maxnum = 0;
		// // 补全边界条件，非空和1，用的是empty函数
		// if(nums.empty() || nums.size()<2) return 0;
		 // //这里有一个隐形的错误，就是nums.size()-1，因为底下出现了i+1。
        // // for(int i=0;i<nums.size()-1;i++)
		// // {
			// // if(nums[i+1]-nums[i]>maxnum)
			// // {
				// // maxnum = nums[i+1]-nums[i];
			// // }
		// // }
		// //代码优化
		// for(int i=0;i<nums.size()-1;i++)
			// maxnum = max(nums[i+1]-nums[i],maxnum);
		// return maxnum;		
    // }
// };




// int main()
// {
	// vector<int>nums = {1,3,100};
	// Solution ss;
	// int u = ss.maximumGap(nums);
	// cout<<u<<endl;
	// return 0;
// }



/*第二种解法用基数排序算法。*/


int maxnum(int a[]) // 求一个数组中的最大数是多少
{
	int maxs = 0;
	for (int i=0;i<10;i++)
		maxs = maxs<a[i]?a[i]:maxs;
	return maxs;
}


int bit_weight(int a) //计算容器中最大的数是几位数
{
	int n=0;
	while(a)
	{
		cout<<a<<endl;
		a/=10;
		++n;
	}
	return n;
}



// int main()
// {
	// vector<int>nums = {1,3,100};
	// auto i = max_element(nums.begin(),nums.end()); //返回的是一个最大值的指针，指向最大值
	// int maxnum = *i;
	// cout<<bit_weight(*i)<<endl;
	
	// return 0;
// }


void radixSort(int data[], int n) //基数排序  
{  
    int d = 3; //最大数的位数是3
    int tmp[n];  
    int count[10]; //计数器  
    int i, j, k;  
    int radix = 1;  
    for(i = 1; i <= d; i++) //进行d次排序  
    {  
        for(j = 0; j < 10; j++)  
            count[j] = 0; //每次分配前清空计数器  
		
		
		
        for(j = 0; j < n; j++)  
        {  
            k = (data[j] / radix) % 10; //统计每个桶中的记录数  
            count[k]++;  
        } 

		
        for(j = 1; j < 10; j++)                 //这一步太牛逼了！
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶  
		
		
		
        for(j = n - 1; j >= 0; j--)             //将所有桶中记录依次收集到tmp中  
        {  
            k = (data[j] / radix) % 10;  
			// cout<<k<<" ";
            tmp[count[k] - 1] = data[j];  
            count[k]--;  
        } 
		// cout<<endl;
        for(j = 0; j < n; j++)                  //将临时数组的内容复制到data中  
            data[j] = tmp[j];  
        radix = radix * 10;  
    }  
}  

/*
	0 0 1 3 3 0 1 0 1 1
	0 0 1 4 7 7 8 8 9 10
	9 6 3 4 4 4 8 2 3 3
	tmp
	542 53 3 63 14 214 154 616 748 589
	1 3 0 0 2 2 1 0 1 0
	1 4 4 4 6 8 9 9 10 10
	8 4 1 5 1 1 6 0 5 4
	tmp
	3 14 214 616 542 748 53 154 63 589
	4 1 1 0 0 2 1 1 0 0
	4 5 6 6 6 8 9 10 10 10
	5 0 1 0 7 5 6 2 0 0
	tmp
	3 14 53 63 154 214 542 589 616 748
*/




int main()
{
	int a[10]={53,3,542,748,14,214,154,63,616,589};
	
	cout<<maxnum(a)<<endl;
	
	
	vector<int> vec(a,a+10);
	radixSort(a,10);

	for(int i=0;i<10;++i)
	{
		cout<<a[i]<<" ";
	}
	
	cout<<endl;
	return 0;
}


















































