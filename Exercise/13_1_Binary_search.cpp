#include<iostream>
using namespace std;

int Binary_search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;
	high=n;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(key<a[mid])
			high = mid-1;
		else if(key>a[mid])
			low = mid+1;
		else
			return mid;
	}
	return 0;
		
}




int main()
{
	int a[11] = {0,1,16,24,35,47,59,62,73,88,99};
	cout<<Binary_search(a,11,62)<<endl;
	return 0;
}


























