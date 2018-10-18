#include<iostream>
using namespace std;

/**
 * Input: 11
Output: 3
Explanation: Integer 11 has binary representation 
00000000000000000000000000001011 
*/
int hammingWeight(uint32_t n)
{
    int res=0;
    for(int i=0;i<32;i++)
    {
        if(n&1)
        {
            res+=1;
        }
        n = n>>1;
    }
    return res;
}