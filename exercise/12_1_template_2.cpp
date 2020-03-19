#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Seqstack
{
	public:
	Seqstack(T a[],int n=0);
	~Seqstack();
	int IsEmpty();
	int IsFull();
	Seqstack<T> &push(T x);
	Seqstack<T> &pop(T &x);
	T Gettop();
	void ShowStack();
	
	private:
	T data[Maxsize];
	int top;
	
};

template<typename T>
Seqstack<T>::Seqstack(T a[],int n=0)
{
	for(int i=0;i<n;i++)
		data[i] = a[i];
	top = n-1;
}


template<typename T>
int Seqstack<T>::IsEmpty()
{
	return (top==-1);		
}

template<typename T>
int Seqstack<T>::IsFull()
{
	return (top==Maxsize-1);		
}

template<typename T>
void Seqstack<T>::ShowStack()
{
	int i=top;
	while(i>0)
	{
		cout<<data[i]<<" ";
		i--;
	}
	cout<<endl;
}

int main()
{
	int a = 9,b=10;
	cout<<max1(a,b);
	return 0;
}