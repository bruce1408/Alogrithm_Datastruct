#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * 题目是要求数组的度，就是包含重复最多元素的最小子序列，必须是连续的；度就是重复
 * 数字最多的元素，切下标之差最小的
 * 比如 1，2，2，3，1；2重复了2次，而且最小子序列包含2 的长度是2，返回的就是2
 * [1,2,2,3,1,4,2]，重复最多的元素是2，包含2的连续子序列的长度是6，返回6；
 * */

// int findShortestSubArray(vector<int>& nums)
// {
//     int degree = 0;
//     if(nums.size()==1) return 1;
//     int count=0,numMax = 0,result=0;
//     unordered_map<int,int> res,startIdx;
//     for(int i=0;i<nums.size();i++)
//     {
//         ++res[nums[i]];
        
//         if(count<res[nums[i]])
//         {
//             count = res[nums[i]];
//             numMax = nums[i];
//         }
//     }
//     int index1=0,index2;
//     for(int i=0;i<nums.size();i++)
//     {
//         if(nums[i]==numMax)
//         {
//             index1 = i;    
//             break;    
//         }
//     }
//     for(int i=index1+1;i<nums.size();i++)
//     {
//         if(nums[i]==numMax && index1!=index2) index2 = i;
//     }
    
//     return index2 - index1 + 1;
// }


/*
    方法二：只用一个哈希表，
    上面的方法有错误，这个方法思路跟上面的解法很相似，还是要建立数字出现次数的哈希表，
    还有就是建立每个数字和其第一次出现位置之间的映射，那么我们当前遍历的位置其实可以看作是尾位置，
    还是可以计算子数组的长度的。我们遍历数组，累加当前数字出现的次数，如果某个数字是第一次出现，
    建立该数字和当前位置的映射，如果当前数字的出现次数等于degree时，当前位置为尾位置，
    首位置在startIdx中取的，二者做差加1来更新结果res；如果当前数字的出现次数大于degree，
    说明之前的结果代表的数字不是出现最多的，直接将结果res更新为当前数字的首尾差加1的长度，
    然后degree也更新为当前数字出现的次数
*/
int findShortestSubArray(vector<int> &nums)
{
    int num = INT_MAX;
    int degree = 0;
    unordered_map<int, int> res,startIdx;
    for(int i=0;i<nums.size();i++)
    {
        ++res[nums[i]];  // 每个元素出现的次数
        if(!startIdx.count(nums[i])) startIdx[nums[i]] = i; // 每个元素的首次出现的位置
        if(res[nums[i]]==degree)  //如果满足degree的话，那么就找到最小长度的作为输出结果
        {
            num = min(num, i-startIdx[nums[i]] + 1);
        }
        else if(res[nums[i]]>degree) // 如果你当前的次数比度还打，那么就更新度
        {
            num = i-startIdx[nums[i]]+1;
            degree = res[nums[i]];
        }
    }
    return num;
}

/*
    方法三：一个哈希表；但是记录的是每个元素出现的位置的下标，思路很自然
*/
int findShortestSubArray1(vector<int> &nums)
{
    int degree = 0;
    unordered_map<int,vector<int>> res;
    for(int i=0;i<nums.size();i++)
    {
        res[nums[i]].push_back(i);
    }
    // find degree
    for(auto ele:res)
    {
        degree = max((int)ele.second.size(), degree);
    }
    // 找到度相同的最小长度
    int length = nums.size();
    for(auto ele:res)
    {
        if(ele.second.size()==degree)
        {
            length = min(length, ele.second.back()-ele.second[0]+1);
        }        
    }
    return length;
}
int main()
{
    vector<int>nums = {1, 1,2,2,2,1};
    cout<<findShortestSubArray1(nums);
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

