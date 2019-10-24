#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> res(rowIndex + 1, 1);
    for (int i = 1; i < rowIndex; i++)
    {
        res[i] = factori(rowIndex) / (factori(i) * factori(rowIndex - i));
    }
    return res;
}

int main()
{
    int num = 5;
    for (auto x : getRow1(num))
    {
        cout << x << " ";
    }
}
