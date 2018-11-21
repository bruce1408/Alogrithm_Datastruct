#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * 题目是要求数组的度，就是包含重复最多元素的最小子序列，必须是连续的；
 * 比如 1，2，2，3，1；2重复了2次，而且最小子序列包含2 的长度是2，返回的就是2
 * [1,2,2,3,1,4,2]，重复最多的元素是2，包含2的连续子序列的长度是6，返回6；
 * */

int findShortestSubArray(vector<int>& nums)
{
    if(nums.size()==1) return 1;
    int count=0,numMax = 0,result=0;
    unordered_map<int,int> res;
    for(int i=0;i<nums.size();i++)
    {
        ++res[nums[i]];
        if(count<res[nums[i]])
        {
            count = res[nums[i]];
            numMax = nums[i];
        }
    }
    // cout<<numMax<<endl;
    int index1=0,index2;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==numMax)
        {
            index1 = i;    
            break;    
        }
    }
    for(int i=index1+1;i<nums.size();i++)
    {
        if(nums[i]==numMax && index1!=index2) index2 = i;
    }
    // cout<<"index2 is:"<<index2<<endl;
    
    return index2 - index1 + 1;
}

int main()
{
    vector<int>nums = {1,1,2,2,2,1};
    cout<<findShortestSubArray(nums);
    return 0;
}


// #include <iostream>
// #include <string>
// #include <unordered_map>

// int main ()
// {
//   std::unordered_map<std::string,int> mymap = 
//   {{ "Mars", 3000},{ "Saturn", 60000},{ "Jupiter", 70000 } };

//   mymap.at("Mars") = 3396;
//   mymap.at("Saturn") += 272;
//   mymap.at("Jupiter") = mymap.at("Saturn") + 9638;

//   for (auto& x: mymap) {
//     std::cout << x.first << ": " << x.second << std::endl;
//   }

//   return 0;
// }

