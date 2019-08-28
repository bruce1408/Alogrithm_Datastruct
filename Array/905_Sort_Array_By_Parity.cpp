#include<iostream>
#include<vector>
using namespace std;


// vector<int> sortArrayByParity(vector<int>& A) 
// {
//     /*
//         偶数全部放前面，奇数全部放后面 [3,2,1,4]==> [2,4,1,3]
//         不过复杂度来讲的话太高了；
//     */
//     int j=0;
//     for(int i=0;i<A.size();i++)
//     {
//         if(A[i]%2!=0)
//         {
//             j=i;
//             while(j<A.size())
//             {
//                 if(A[j]%2==0) break;
//                 else ++j;
//             }
//             if(i<A.size() && j<A.size()) swap(A[i],A[j]);
//         }
//     }
//     return A;
// }


// // 方法二：
// vector<int> sortArrayByParity(vector<int>& A) 
// {
//     std::sort(A.begin(), A.end(), [](int& a,int& b)->bool{ return a % 2 < b % 2; });
//     return A;
// }

// 方法三： 重点掌握的方法
// vector<int> sortArrayByParity(vector<int>& A) 
// {
//     int last = 0;
//     for(int i = 0; i < A.size(); i++)
//     {
//         if(!(A[i] & 1)) // 是偶数
//         {
//             int t  = A[last];
//             A[last] = A[i];
//             A[i] = t;
//             last++;
//         }
//     }
//     return A;       
// }



vector<int> sortArrayByParity(vector<int>& A)
{
    int len = A.size();
    int slow = 0, fast=0;
    while(fast<len)
    {
        if((A[slow]&1)==1)
        {
            fast=1+slow;
            while(fast<len)
            {
                if((A[fast]&1)==0)
                {
                    int temp = A[slow];
                    A[slow] = A[fast];
                    A[fast] = temp;
                    break;
                }
                fast+=1;
            }
        }
        else slow+=1;
    }
}

vector<int> sortArrayByParity(vector<int>& A) 
{
    /*
        偶数全部放前面，奇数全部放后面 [3,2,1,4]==> [2,4,1,3]
        不过复杂度来讲的话太高了；
    */
    int j=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]%2!=0)
        {
            j=i;
            while(j<A.size())
            {
                if(A[j]%2==0) break;
                else ++j;
            }
            if(i<A.size() && j<A.size()) swap(A[i],A[j]);
        }
    }
    return A;
}


vector<int> sortArrayByParity4(vector<int>& A)
{
    int fast = 0;
    for (int i=0;i<A.size();i++)
    {
        if(!A[i]&1)
        {
            int temp = A[i];
            A[fast] = A[i];
            A[fast] = temp;
        }
        fast++;
    }
    return A;
}


int main()
{
    vector<int> re = {3,1,2,4};
    for(auto i:sortArrayByParity4(re))
// 方法二：
vector<int> sortArrayByParity(vector<int>& A) 
{
    sort(A.begin(), A.end(), [](int& a,int& b)->bool{ return a % 2 < b % 2; });
    return A;
}

// 方法三： 重点掌握的方法
vector<int> sortArrayByParity(vector<int>& A) 
{
    int last = 0;
    for(int i = 0; i < A.size(); i++)
    {
        if(!(A[i] & 1)) // 是偶数
        {
            int t  = A[last];
            A[last] = A[i];
            A[i] = t;
            last++;
        }
    }
    return A;       
}

int main()
{
    vector<int> re = {3,2,1,4};
    for(auto i:sortArrayByParity(re))
    {
        cout<<i<<endl;
    }
    return 0;
}