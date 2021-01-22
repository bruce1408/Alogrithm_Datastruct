#include <iostream>
#include <vector>
using namespace std;

int findNums(vector<int> &res, int k)
{
    int l = 0, r = res.size();
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (res[mid] >= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int lastGreater(vector<int> &res, int k)
{
    int l = 0, r = res.size();
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (res[mid] < k)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{

    vector<int> res = {1, 2, 3, 4, 5, 7, 8, 9};
    int n, k;
    cout << "input a nums n" << endl;
    cin >> n;
    while (n--)
    {
        cin >> k;
        cout << "target x first location is: " << findNums(res, k) << endl;
        cout << "target x last location is: " << lastGreater(res, k) << endl;
    }
}