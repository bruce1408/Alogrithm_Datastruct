#include <iostream>
#include <vector>
using namespace std;

/**
 * 
*/
bool find_num(int (*a)[4],int rows, int columns, int key)
{
	if(a!=nullptr && rows >0 && columns>0)
	{
		int row = 0; 
		int column = columns-1;
		while(row<rows && column>=0)
		{
			if(a[row][column]==key)
			{
				return true;
			}
			else if(a[row][column]>key)
			{
				column--;
			}
			else
				++row;
		}
	}
	return false;
}

int main()
{
	int a[4][4]=
	{
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}
	};
	cout<<find_num(a,4,4,4)<<endl;
}