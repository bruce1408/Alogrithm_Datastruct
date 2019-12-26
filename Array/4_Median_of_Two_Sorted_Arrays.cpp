#include<iostream>
#include<vector>
using namespace std;


/**
 * 方法 1, 直接合并然后讨论。但是时间复杂度是O(n+m)
 * */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    vector<int> res;
    if(nums1.size()==0 && nums2.size()==0) return 0;
    else if(nums1.size()==0 && nums2.size()!=0)
    {
        return (nums2.size()%2==1 ? (double)nums2[len2/2] : (double)(nums2[len2/2]+nums2[len2/2-1])/2);
    }
    else if(nums1.size()!=0 && nums2.size()==0)
    {
        return (nums1.size()%2==1 ? (double)nums1[len1/2] : (double)(nums1[len1/2]+nums1[len1/2-1])/2);
    }
    else
    {
        int i=0, j=0;
        while(i<len1 && j<len2)
        {
            if(nums1[i]<nums2[j])
            {
                res.push_back(nums1[i++]);
            }
            else
            {
                res.push_back(nums2[j++]);
            }
        }
        while(i<len1)
        {
            res.push_back(nums1[i++]);
        }
        while(j<len2)
        {
            res.push_back(nums2[j++]);
        }
    }
    int len = res.size();
    return (len%2==1 ? (double)res[len/2] : (double)(res[len/2]+res[len/2-1])/2);
}


/**
 * 方法 2，利用的是二分查找，这样你的时间复杂度才可能是O(log(min(n,m)))
 * ubuntu 里面的INT_MAX 要改成 INT64_MIN 才可以
 * */ 
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2)
{
    int len1 = nums1.size(), len2 = nums2.size(), k = (len1 + len2 + 1) / 2;
    if(len1>len2) return findMedianSortedArrays2(nums2, nums1);
    int cutL = 0, cutR = len1;
    int m1 = 0, m2 = 0;
    while(cutL < cutR)
    {
        m1 = (cutL + cutR)/2;
        m2 = k-m1;
        if (nums1[m1]<nums2[m2-1])
        {
            cutL = m1+1;
        }
        else
        {
            cutR = m1;
        }
    }
    
    const int c1 = max(m1 <= 0 ? INT64_MIN : nums1[m1 - 1], m2 <= 0 ? INT64_MIN : nums2[m2 - 1]);

    if ((len1 + len2) % 2 == 1)
        return c1;    
        
    const int c2 = min(m1 >= len1 ? INT64_MAX : nums1[m1], m2 >= len2 ? INT64_MAX : nums2[m2]);
    cout<<c1<<" and "<<c2<<endl;
    return (c1 + c2) / 2.0;
}

/**
 * 有点问题
 * */ 
double findMedianSortArrys3(vector<int> &num1, vector<int>& num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if(len1 > len2) return findMedianSortArrys3(num2, num1);
    int low = 0;
    int high = len1;
    while(low<=high)
    {
        int partitionX = (low+high)/2;
        int partitionY = (len1 + len2 +1)/2 - partitionX;
        
        int maxLeftx = (partitionX == 0)? INT64_MIN:num1[partitionX-1];
        int minrightx = (partitionX == len1)?INT64_MAX:num1[partitionX];

        int maxLefty = (partitionY == 0)? INT64_MIN:num1[partitionY-1];
        int minrighty = (partitionY == len2)?INT64_MAX:num1[partitionY];

        if(maxLeftx <= minrighty && maxLefty <= minrightx)
        {
            if((len1 + len2)%2==0) return (max(maxLeftx, maxLefty) + max(minrightx, minrighty))/2;
            else return max(maxLeftx, maxLefty);
        }
        else if (maxLeftx > minrighty) high = partitionX - 1;
        else low = partitionX + 1;
    }
}

/**
 * 方法 4，把 nums1 和 nums2 都放到同一个temp的临时数组中，然后判断新数组元素个数是不是偶数
 * 如果是偶数的话，那么就除以2，否则奇数直接计算即可
*/
double findMedianSortedArrays4(vector<int>& nums1, vector<int>& nums2) {
    vector<int>temp;
    while(!nums1.empty() && !nums2.empty())
    {
        if(nums1.back()> nums2.back())
        {
            temp.push_back(nums1.back());
            nums1.pop_back();
        }
        else
        {
            temp.push_back(nums2.back());
            nums2.pop_back();
        }
    }
    while(!nums1.empty())
    {
        temp.push_back(nums1.back());
        nums1.pop_back();
    }
    while(!nums2.empty())
    {
        temp.push_back(nums2.back());
        nums2.pop_back();
    }
    int n = temp.size();
    if(n%2==0)
    {
        return (temp[n/2] + temp[n/2-1])/2.0;
    }
    else
    {
        return temp[n/2];
    }
}


int main()
{
    vector<int> a = {1, 3, 5, 9};
    vector<int> b = {2, 4, 6, 8, 10, 12, 14, 16};
    cout<<findMedianSortedArrays2(a, b)<<endl;
    return 0;
}