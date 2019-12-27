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
    m1 = cutL, m2 = k - cutL;
    
    const int c1 = max(m1 <= 0 ? INT64_MIN : nums1[m1 - 1], m2 <= 0 ? INT64_MIN : nums2[m2 - 1]);

    if ((len1 + len2) % 2 == 1)
        return c1;    
        
    const int c2 = min(m1 >= len1 ? INT64_MAX : nums1[m1], m2 >= len2 ? INT64_MAX : nums2[m2]);
    cout<<c1<<" and "<<c2<<endl;
    return (c1 + c2) / 2.0;
}


double findMedianSortedArrays22(vector<int>& nums1, vector<int>& nums2)
{
    if (nums1.empty())
    {
        int n2 = nums2.size();
        if (n2%2==0)
        {
            return (nums2[n2/2]+nums2[n2/2-1])/2.0;
        }
        else
        {
            return nums2[n2/2];
        }
        
    }
    else if(nums2.empty())
    {
        int n1 = nums1.size();
        if(n1%2==0)
        {
            return (nums1[n1/2] + nums1[n1/2-1])/2.0;
        }
        else
        {
            return nums1[n1/2];
        }
    }
    else
    {
        int len1 = nums1.size(), len2 = nums2.size(), k = (len1 + len2 + 1) / 2;
        if(len1>len2) return findMedianSortedArrays22(nums2, nums1);
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
        m1 = cutL, m2 = k - cutL;
        
        // const int c1 = max(m1<=0?INT_MIN:nums1[m1 - 1], m2<=0?INT_MIN:nums2[m2 - 1]);
        const int c1 = max(m1<=0?INT64_MIN:nums1[m1 - 1], m2<=0?INT64_MIN:nums2[m2 - 1]);


        if ((len1 + len2) % 2 == 1)
            return c1;    
        const int c2 = min(m1>=len1?INT64_MAX:nums1[m1], m2>=len2?INT64_MAX:nums2[m2]);
        cout<<c1<<" and "<<c2<<endl;
        return (c1 + c2) / 2.0;
    }
}


double findMedianSortedArrays3(vector<int> &num1, vector<int>& num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if(len1 > len2) return findMedianSortedArrays3(num2, num1);
    int low = 0;
    int high = len1;
    while(low<=high)
    {
        int partitionX = (high+low)/2;
        int partitionY = (len1 + len2 +1)/2 - partitionX;
        
        // int maxleftx = (partitionX == 0)? INT64_MIN:num1[partitionX-1];
        // int minrightx = (partitionX == len1)? INT64_MAX:num1[partitionX];

        // int maxlefty = (partitionY == 0)? INT64_MIN:num2[partitionY-1];
        // int minrighty = (partitionY == len2)? INT64_MAX:num2[partitionY];

       
        // if(maxleftx > minrighty) high = partitionX -1;
        // else if(maxlefty > minrightx) low = partitionX + 1 ;
        // else
        // {
        //     return (len1 + len2)%2? min(minrightx, minrighty):(max(maxleftx, maxlefty) + min(minrightx, minrighty))/2.0;
        // }

        if(partitionX && num1[partitionX-1] > num2[partitionY])
        {
            high = partitionX-1;
        }
        else if(partitionX < len1 && num2[partitionY-1]>num1[partitionX])
        {
            low = partitionX + 1;
        }
        else
        {
            int maxleft = (partitionX==0)? num2[partitionY-1]: (partitionY==0?num1[partitionX-1]:max(num1[partitionX-1], num2[partitionY-1]));
            if((len1 + len2)%2)
            {
                return maxleft;
            }
            int minright = (partitionX==len1)? num2[partitionY]:(partitionY==len2?num1[partitionX]:min(num1[partitionX],num2[partitionY]));
            return (minright + maxleft )*0.5;
        }
        
    return 0.0;
    }
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size(), l = 0, r = m;
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }
    while (l <= r) {
        int i = (l + r) / 2, j = (m + n + 1) / 2 - i;
        if (i && nums1[i - 1] > nums2[j]) {
            r = i - 1;
        } else if (i < m && nums2[j - 1] > nums1[i]) {
            l = i + 1;
        } else {
            int lmax = !i ? nums2[j - 1] : (!j ? nums1[i - 1] : max(nums1[i - 1], nums2[j - 1]));
            if ((m + n) % 2) {
                return lmax;
            }
            int rmin = i == m ? nums2[j] : (j == n ? nums1[i] : min(nums1[i], nums2[j]));
            return 0.5 * (lmax + rmin);
        }
    }
    return 0.0;
}

double findMedianSortedArrays33(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2) return findMedianSortedArrays33(nums2, nums1);	// Make sure A2 is the shorter one.
    
    int lo = 0, hi = N2 * 2;
    while (lo <= hi) {
        int mid2 = (lo + hi) / 2;   // Try Cut 2 
        int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly
        
        double L1 = (mid1 == 0) ? INT64_MIN : nums1[(mid1-1)/2];	// Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT64_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == N1 * 2) ? INT64_MAX : nums1[(mid1)/2];
        double R2 = (mid2 == N2 * 2) ? INT64_MAX : nums2[(mid2)/2];
        
        if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1) hi = mid2 - 1;	// A2's lower half too big; need to move C2 left.
        else return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.
    }
    return -1;
} 

/**
 * 方法 4，把 nums1 和 nums2 都放到同一个temp的临时数组中，然后判断新数组元素个数是不是偶数
 * 如果是偶数的话，那么就除以2，否则奇数直接计算即可,时间复杂度是O(n+m)
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
    vector<int> a = {1,3};
    vector<int> b = {2};
    cout<<findMedianSortedArrays3(a, b)<<endl;
    return 0;
}