#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * We have an array A of integers, and an array queries of queries.
 * For the i-th query val = queries[i][0], index = queries[i][1], 
 * we add val to A[index].  Then, the answer to the i-th query is the 
 * sum of the even values of A.(Here, the given index = queries[i][1] is
 * a 0-based index, and each query permanently modifies the array A.)
 * Return the answer to all queries.  Your answer array should have 
 * answer[i] as the answer to the i-th query.
 * 
 * Example 1:
 * Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
 * Output: [8,6,2,4]
 * 
 * 按照给的queries来计算出一个结果，queries的第一列的元素是表示加的数值，第二列表示
 * 元素下标，按照相应的下标来加上值，如果是偶数的话就存放到结果数组中去即可。
 * */

/**
 * 方法 1，每次更新之后就累加一次新的数组中偶数的和，但是时间复杂度较高
 * 是O(M*N),M和N分别是两个数组的长度，方法超时了
*/
vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
{
    vector<int> res;
    vector<int> even(A.size());
    for (int i = 0; i < queries.size(); i++)
    {
        int val = queries[i][0];
        int index = queries[i][1];
        A[index] += val;
        int sum = 0;
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] % 2 == 0)
            {
                sum += A[j];
            }
        }
        res.push_back(sum);
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
 * 方法 3,更加精简，只判断是不是偶数即可，如果当前选择的数字是偶数的话，那么
 * sum之和减去这个数字，因为要重新求和，然后这个数字A[index]+=value，更新
 * A[index],再次判断这个数字是不是偶数，如果还是偶数的话，那么sum重新加上
 * 这个数，更新sum；从头到尾，只判断是不是偶数即可，比方法 4要简洁一些。
*/
vector<int> sumEvenAfterQueries2(vector<int> &A, vector<vector<int>> &queries)
{
    vector<int> res;
    int sum = 0;
    for (int i = 0; i < A.size(); i++) // 所有偶数相加
    {
        if (A[i] % 2 == 0)
        {
            sum += A[i];
        }
    }
    for (int i = 0; i < queries.size(); i++)
    {
        int num = queries[i][0]; // value 
        int index = queries[i][1]; // index 下标
        if (A[index] % 2 == 0) sum -= A[index];
        A[index] += num;
        if (A[index] % 2 == 0)
        {
            sum += A[index];
        }

        res.push_back(sum);
    }
    return res;
}

/**
 * 方法 4，和方法2，3，都是一样的思路。但是判断的情况略冗余；
 * 自己再做一次，思路是按照题目的理解来写，分四种情况，
 * 当前的值原来是偶数，现在是奇数的情况，减去原来的对应元素的值
 * 当前的值原来是偶数，现在是偶数的情况，加上现在的value值
 * 当前的值原来是奇数，现在是偶数的情况，加上现在index对应的值
 * 当前的值原来是奇数，现在是奇数的情况；
*/
vector<int> sumEvenAfterQueries4(vector<int> &A, vector<vector<int>> &queries)
{
    int sum = 0;
    vector<int> res;
    for (int i = 0; i < A.size(); i++)
    {
        if ((A[i] & 1) == 0)
            sum += A[i];
    }
    for (int i = 0; i < queries.size(); i++)
    {
        int index = queries[i][1];
        int value = queries[i][0];
        int temp = A[index]; // old value
        A[index] += value; // new value
        if (temp%2 == 0)  // 原来是偶数
        {
            if (A[index]%2==0)
                sum += value;
            else sum -= temp;
        }
        else // 原来是奇数
        {
            if (A[index]%2 == 0)
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
    for (auto i : sumEvenAfterQueries4(a, queries))
    {
        cout << i << " ";
    }
}