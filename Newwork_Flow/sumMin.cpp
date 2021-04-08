#include <iostream>
#include <vector>
using namespace std;

/**
 * 给一个 nxm 的二维数组，然后每一列取一个值，得到一个1xm的数组b，
 * 使得这个数组sum(abs(b[i]-b[i+1])) 最小
 **/
int numMin(vector<vector<int> > res)
{
    int n = res.size(), m = res[0].size(); // n = 3 , m = 5
    // int ans = INT_MAX;

    vector<int> preSum(n, 0);
    vector<int> minsum(n, 0);
    for (int col = 1; col < m; col++)
    {
        for (int row = 0; row < n; row++)
        {
            int ans = INT_MAX;
            for (int index = 0; index < n; index++)
            {
                ans = min(ans, abs(res[row][col] - res[index][col - 1]) + preSum[index]);
                minsum[row] = ans;
            }
        }

        for (auto x : minsum)
            cout << x << " ";
        cout << endl;
        preSum = vector<int>(minsum);
    }
    int cnt = INT_MAX;
    for (auto x : minsum)
        cnt = min(cnt, x);
    return cnt;
}

int main()
{
    vector<vector<int> > res = {
        {5, 9},
        {4, 7},
        {2, 9}};
    cout << numMin(res);
}