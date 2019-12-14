#include<iostream>
#include<vector>
using namespace std;

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 * 
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
*/
/**
 * 第一种方法：直接合并然后讨论。但是时间复杂度是O(n+m)
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
 * 第二种方法，利用的是二分查找，这样你的时间复杂度才可能是O(log(n+m))
 * */ 
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2)
{
    int len1 = nums1.size();
    int len2 = nums2.size();
    if(len1>len2) return findMedianSortedArrays(nums2, nums1);
    int cut1 = 0; 
    int cut2 = 0;
    int cutL = 0, cutR = len1;
    int len = len1 + len2;
    while(cut1<=len1)
    {
        cut1 = (cutR - cutL)/2 + cutL;
        cut2 = len / 2 - cut1;
        double L1 = (cut1==0)?INT_MIN:nums1[cut1-1];
        double L2 = (cut1==0)?INT_MIN:nums2[cut2-1];
        double R1 = (cut1==len1)?INT_MAX:nums1[cut1];
        double R2 = (cut2==len2)?INT_MAX:nums2[cut2];
        // 关键步骤
        if(L1>R2) {cutR = cut1 - 1;} // 如果是不满足，那么左切口向左移动一位
        else if(L2>R1) //  第二个数组的左边大于右边的话，那么肯定是第一个切口要向右边移动；
        {
            cutL = cut1 + 1;
        }
        else // 满足条件L1<R2,L2<R1
        {
            return (len/2==0)?(max(L1,L2) + min(R1,R2)) / 2 : min(R1,R2);
        }
    }
    return 0;
}

// 有点问题
double findMedianSortArrys3(vector<int> &num1, vector<int>& num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if(len1 > len2) return findMedianSortArrys3(num2, num1);
    int low = 0;
    int high = len1;
    while(low<=high)
    {
        int partitionx = (low+high)/2;
        int partitiony = (len1 + len2 +1)/2 - partitionx;
        
        int maxLeftx = (partitionx == 0)? INT_MIN:num1[partitionx-1];
        int minrightx = (partitionx == len1)?INT_MAX:num1[partitionx];

        int maxLefty = (partitiony == 0)? INT_MIN:num1[partitiony-1];
        int minrighty = (partitiony == len2)?INT_MAX:num1[partitiony];

        if(maxLeftx <= minrighty && maxLefty <= minrightx)
        {
            if((len1 + len2)%2==0) return (max(maxLeftx, maxLefty) + max(minrightx, minrighty))/2;
            else return max(maxLeftx, maxLefty);
        }
        else if (maxLeftx > minrighty) high = partitionx - 1;
        else low = partitionx + 1;
    }
}



int main()
{
    vector<int> a = {1, 2};
    vector<int> b = {3, 4};
    cout<<findMedianSortedArrays3(a, b)<<endl;
    return 0;
}