#include <iostream>
#include <vector>
using namespace std;

int maxRotateFunction(vector<int> &A)
{
    int n = A.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < n + i; j++)
        {
            temp += j * A[(i + n + j) % n];
        }
        res = max(res, temp);
    }
    return res;
}

int main()
{
    vector<int> res = {4, 3, 2, 6};
    cout << maxRotateFunction(res) << endl;
}