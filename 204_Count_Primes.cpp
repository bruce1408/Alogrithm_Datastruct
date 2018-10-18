/*204. Count Primes
统计小于某数的所有的素数的个数；




*/

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

/*方法1，小一点的数没问题，但是过大会引起超时，TLE问题。*/
// bool is_primes(int i)
// {
	// for(int j=2;j<=sqrt(i);j++)
	// {
		// if(i%j==0)
			// return false;
	// }
	// return true;
// }

// int countPrimes(int n)
// {
	// int count = 0;
	// for(int i=2;i<n;i++)
	// {
		// if(is_primes(i))
		// {
			// count++;
		// }
			
			
	// }
	// return count;
// }

/*方法2：埃拉托斯特尼筛法 */
class Solution 
{
	public:
    int countPrimes(int n) 
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
            if (num[j]) ++res;
        }
        return res;
    }
};

int main()
{
	cout<<countPrimes(29);
	return 0;
}













