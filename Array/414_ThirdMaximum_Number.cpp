#include<iostream>
#include<vector>
#include<set>
using namespace std;


int thirdMax(vector<int> &nums)
{
    /*
        求数组中最大的第三个数字，先求出数组中最大的第二个数字
        然后依次求解数组中最大的第三个数字
        主要是怎么求解最大的第二个数字，如果第二个数字求解出来了，那么
        第三个最大的数也可以求解    
    */
   if(nums.size()==1) return nums[0]; 
   long max1 = LONG_MIN;
   long max2 = LONG_MIN;
   long max3 = LONG_MIN;
   for(auto i:nums)
   {
       if(i>max1)
       {
           max3 = max2;
           max2 = max1;
           max1 = i;
       }
       else if(i>max2 && i<max1)
       {
           max3 = max2;
           max2 = i;
       }
       else if(i>max3 && i<max2)
       {
           max3 = i;
       }
   }
   return (max3==LONG_MIN || max3==max2)? max1:max3; 
}

// 这个就是用数组来做，但是时间复杂度不满足O（n），了解即可
int thirdMax2(vector<int> &nums)
{
    set<int> s;
    for(int num:nums)
    {
        s.insert(num);  // 自动的从小到大的排序
        if(s.size()>3)
        {
            s.erase(s.begin()); // 永远是3的长度
        }
    }
    return s.size()==3?*s.begin():*s.end();
}

int main()
{
    vector<int> nums = {2,1,-2147483648};
    cout<<thirdMax(nums);
    set<int>h;
    h.insert(3);
    h.insert(2);
    h.insert(6);
    
    return 0;
}