#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

int main()
{
	vector<int> m1 = {1,2,3,4,5};
	vector<int> ::reverse_iterator iter = m1.rbegin();
	while(iter != m1.rend())
		cout<<*iter++<<" ";
	cout<<endl;
	return 0;
}