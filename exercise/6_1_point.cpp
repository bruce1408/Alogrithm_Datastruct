#iclude < iostream>
using namespace std;
/**
 * 指针保存的就是变量的地址
*/
int main()
{
	//单独给a，b指针，然后让a，b指向空NULL，然后依然不能赋值；但是new可以。
	int *a = new int;
	int *b = new int;
	*a = 10;
	*b = 11;
	cout << *a << endl;
	cout << *b << endl;
	delete a;
	a = nullptr;
	delete b;
	b = nullptr;

	return 0;
}
