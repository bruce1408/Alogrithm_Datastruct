#include<iostream>
#include<cstdlib>
using namespace std;

#define DEBUG

int main()
{
	int i = 0;
	char c ;
	while(1)
	{
		i++;
		c = getchar();
		if(c!='\n')
		{
			getchar();
		}
		if(c=='q'||c=='Q')
		{
			#ifdef DEBUG
			cout<<"we got  %c,about to exit.\n"<<c<<" ";
			#endif
			break;
		}
		else
		{
			cout<<i<<" ";
			#ifdef DEBUG
			cout<<c<<endl;
			#endif
			
			
		}
	}
	
	return 0;
	
	
	
}



























