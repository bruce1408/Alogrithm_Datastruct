/*556 和 503题目
	要求是一个数字 12 能变成大于它的数，21，返回21,123 变成 132。找不到这样
	的数字那么就返回-1。
	这道题目关键是！从后往前依次遍历！
	比如12443322，这个数字的重排序结果应该为13222344，
	如果我们仔细观察的话会发现数字变大的原因是左数第二位的2变成了3，
	细心的童鞋会更进一步的发现后面的数字由降序变为了升序，这也不难理解，
	因为我们要求刚好比给定数字大的排序方式。那么我们再观察下原数字，
	看看2是怎么确定的，我们发现，如果从后往前看的话，
	2是第一个小于其右边位数的数字，因为如果是个纯降序排列的数字，
	做任何改变都不会使数字变大，直接返回-1。知道了找出转折点的方法，
	再来看如何确定2和谁交换，这里2并没有跟4换位，而是跟3换了，
	那么如何确定的3？其实也是从后往前遍历，找到第一个大于2的数字交换，
	然后把转折点之后的数字按升序排列就是最终的结果了。
	最后记得为防止越界要转为长整数型，然后根据结果判断是否要返回-1即可*/


#include<iostream>  
#include<algorithm> 
#include<stack> 
#include<string>
#include<climits> // INT_MAX
using namespace std; 

//方法1
int nextGreaterElement(int n)
{
	string str = to_string(n);
	int len = str.size();
	int i=len-1;
	for(;i>0;i--)   //找到那个要交换的数字 1243，交换的是2，但是找到的是4的位置
	{
		if(str[i]>str[i-1])
			break;
	}
	if (i == 0) return -1;
	//找到上面和他交换的数字，2要交换的数字是3，下面就是找3，然后从2开始，升序排序
	for(int j = len-1;j>=i;j--) 
	{
		if(str[j]>str[i-1])
		{
			swap(str[j],str[i-1]);
			break;
		}
	}
	sort(str.begin()+i,str.end());  //从2开始，升序排序
	long long res = stoll(str);     //字符串转换成有符号长整型。
	//为了防止越界，用INT_MAX，它的头文件是#include<climits>，范围是21.47亿(32位)
	return res > INT_MAX ? -1 : res;
}
 
//方法2
class Solution 
{
	public:
    int nextGreaterElement(int n) 
	{
        string str = to_string(n);
        next_permutation(str.begin(), str.end());//下一个全排列
        long long res = stoll(str);
        return (res > INT_MAX || res <= n) ? -1 : res;//判断是否越界
    }
};
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int main()
{	
	
    int a = 1243;
	cout<<nextGreaterElement(a);
	
		
	return 0;
}




































