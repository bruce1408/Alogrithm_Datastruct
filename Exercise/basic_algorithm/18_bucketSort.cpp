#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/**
 * 基于桶排序的排序算法
*/
void bucketsort(vector<int> &arr)
{
    queue<int> buckets[10];
    for (int digit = 1; digit <= 1e9; digit *= 10)
    {
        for (int elem : arr)
            buckets[(elem / digit) % 10].push(elem);
        int idx = 0;
        for (queue<int> &bucket : buckets)
        {
            while (!bucket.empty())
            {
                arr[idx++] = bucket.front();
                bucket.pop();
            }
        }
    }
}

int main()
{
    vector<int> test = {40, 8, 2, 15, 37, 42, 11, 29, 24, 7};
    bucketsort(test);
    for (auto x : test)
        cout << x << " ";
    cout << endl;
    return 0;
}