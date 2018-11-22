#include<iostream>
#include<vector>
using namespace std;

// 证明一个单调的数组。两个指针的情况或者是两个标志位

// 方法一：下面总有一个一直是true的情况
// bool isMonotonic(vector<int>& A)
// {
//     bool incflag = true, decflag = true;
//     for (int i =0;i<A.size()-1;i++)
//     {
//         incflag &=A[i+1]<=A[i];
//         decflag &=A[i+1]>=A[i];
//     }
//     return incflag || decflag;
// }

// 方法二： 使用两个指针
bool isMonotonic(vector<int> &A)
{
    int ansDec = 0,ansInc=0;
    int fast = 1,slow = 0;
    while(fast<A.size())
    {
        if(A[fast]-A[slow]>=0) ansDec++;
        if(A[fast]-A[slow]<=0) ansInc--;
        fast++;
        slow++;
    }
    if(ansDec==A.size()-1 || ansInc == -(A.size()-1)) return true;
    else return false;
}


int main()
{
    vector<int> res  = {1,2,2,3};
    cout<<isMonotonic(res);
    return 0;

}