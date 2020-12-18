#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int res = 1;
    int a = 3, b = 2, c = 5;
    for (int i = 0; i < b; i++)
    {
        res = res * a % c;
    }
    cout << res << endl;
}