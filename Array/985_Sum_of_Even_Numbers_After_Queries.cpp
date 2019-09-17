#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * 方法 1，每次更新之后就累加一次新的数组中偶数的和，但是时间复杂度较高
 * 是O(M*N),M和N分别是两个数组的长度，方法超时了
*/
vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
{
    vector<int> res(A.size());
    vector<int> even(A.size());
    for (int i = 0; i < queries.size(); i++)
    {
        int val = queries[i][0];
        int index = queries[i][1];
        A[index] = A[index] + val;
        int sum = 0;
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] % 2 == 0)
            {
                sum += A[j];
            }
        }
        res[i] = sum;
    }
    return res;
}

/**
 * 方法 2利用一些规律，省掉一层for循环，把时间复杂度降下来
*/
vector<int> sumEvenAfterQueries1(vector<int> &A, vector<vector<int>> &queries)
{
    vector<int> res;
    int sum = 0;
    for (auto i : A)
    {
        if (i % 2 == 0)
            sum += i;
    }

    for (auto q : queries)
    {
        int temp = A[q[1]];
        if (A[q[1]] % 2 == 0)
        {
            if (q[0] % 2 == 0)
                sum += q[0];
            else
                sum -= temp;
            A[q[1]] += q[0];
        }
        else
        {
            A[q[1]] += q[0];
            if (q[0] % 2 != 0)
                sum += A[q[1]];
        }
        res.push_back(sum);
    }
    return res;
}

/**
 * 方法 3,更加精简。
*/
vector<int> sumEvenAfterQueries2(vector<int> &A, vector<vector<int>> &queries)
{
    vector<int> res;
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] % 2 == 0)
        {
            sum += A[i];
        }
    }
    for (int i = 0; i < queries.size(); i++)
    {
        int num = queries[i][0];
        int index = queries[i][1];
        if (A[index] % 2 == 0)
        {
            sum -= A[index];
        }
        A[index] += num;
        if (A[index] % 2 == 0)
        {
            sum += A[index];
        }

        res.push_back(sum);
    }
    return res;
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    vector<vector<int>> queries =
        {
            {1, 0},
            {-3, 1},
            {-4, 0},
            {2, 3}};
    for (auto i : sumEvenAfterQueries2(a, queries))
    {
        cout << i << " ";
    }
}