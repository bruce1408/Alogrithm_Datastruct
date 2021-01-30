#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/**
 * 204. Count Primes统计小于某数的所有的素数的个数；
*/

/**
 * 方法 1，使用常规数学方法，时间复杂度高会超时
*/
bool getprime(int x)
{
	if (x <= 1)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int countPrimes1(int n)
{
	int cnt = 0;
	for (int i = 2; i < n; i++)
	{
		if (getprime(i))
			cnt++;
	}
	return cnt;
}

/**
 * 方法2：埃拉托斯特尼筛法
 */
int countPrimes2(int n)
{
	vector<bool> num(n - 1, true);
	num[0] = false;
	int res = 0, limit = sqrt(n);
	for (int i = 2; i <= limit; ++i)
	{
		if (num[i - 1])
		{
			for (int j = i * i; j < n; j += i)
				num[j - 1] = false;
		}
	}
	for (int j = 0; j < n - 1; ++j)
	{
		if (num[j])
			++res;
	}

	return res;
}

int countPrimes3(int n)
{
	vector<int> res(n);
	vector<bool> p(n);
	int px = 0;
	for (int i = 2; i < n; i++)
	{
		if (p[i] == false)
		{
			res[px++] = i;
			for (int j = i + i; j < n; j += i)
				p[j] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (res[i] != 0)
			ans++;
	}
	return ans;
}

/**
 * 方法 3. 朴素筛法求素数
 * */ 
const int N = 20;
int primes[N], cnt;		// primes[]存储所有素数
bool st[N];			// st[x]存储x是否被筛掉

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i; j <= n; j += i)
            st[j] = true;
    }
}

/** 
 * 4. 线性筛法求素数
 */
int countPrimes4(int n)
{
	vector<bool> st(n + 1);
	vector<int> primes;
	for (int i = 2; i < n; i++)
	{
		if (st[i] == false)
			primes.push_back(i);
		for (int j = 0; primes[j] * i < n; j++)
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0)
				break;
		}
	}
	return primes.size();
}

int main()
{
	cout << countPrimes4(10) << endl;
	return 0;
}
