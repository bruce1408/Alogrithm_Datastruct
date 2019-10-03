#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
 * Given an integer array, return the k-th smallest 
 * distance among all the pairs. 
 * The distance of a pair (A, B) is defined as the 
 * absolute difference between A and B.
 * 
 * Input:
 * nums = [1,3,1]
 * k = 1
 * Output: 0 
 * 
 * Here are all the pairs:
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * Then the 1st smallest distance pair is (1,1), and its distance is 0.
 */

/**
 * 方法 1，
*/
int smallestDistancePair(vector<int>& nums, int k)
{

}


int main()
{
    vector<int> nums = {1, 2, -2147483648};
    cout << thirdMax1(nums);
    return 0;
}