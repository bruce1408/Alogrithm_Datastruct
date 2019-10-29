#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/**
 * In a row of seats, 1 represents a person sitting in that seat, 
 * and 0 represents that the seat is empty. 
 * There is at least one empty seat, and at least one person sitting.
 * Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
 * Return that maximum distance to closest person.
 * 
 * Example 1:
 * Input: [1,0,0,0,1,0,1]
 * Output: 2
 * Explanation: 
 * If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
 * If Alex sits in any other open seat, the closest person has distance 1.
 * Thus, the maximum distance to the closest person is 2.
 */

int maxDistToClosest(vector<int>& seats) 
{
    

}



int main()
{
    vector<int>res=  {1,1,2,2,2,2,2,2,3,3,3,3,3,3,3,3};
    cout<<maxDistToClosest(res)<<endl;
}
