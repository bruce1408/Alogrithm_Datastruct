#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) 
{
    /*
     * function: 一个数组加1，
     * digits 是数组。考虑几种情况：第一种是999，第二种是9，第三种是109；
     * 999 的时候要最高位进位，所以，最后一位补0，最高位重置为1
     * 第三种是109
     */

    int n = digits.size();
    int carry = 0;
    if(digits[n-1]!=9) digits[n-1]+=1;
    else
    {
        carry = 1;
        for(int i=n-1;i>=0;i--)
        {
            if(digits[i]==9 && i!=0 && carry==1)
            {
                digits[i] = 0;
                carry=1;
            }
            else if(digits[i]!=9 && carry==1)
            {
                digits[i] = carry+digits[i];
                carry--;
            }
            else if(digits[i]!=9 && carry==0)
            {
                digits[i] = digits[i];
            }
            else if(digits[i]==9 && i==0 && carry==1)
            {
                digits.push_back(0);
                digits[0] = carry;
            }
        }
    }
    return digits;
}


// 最高位如果是9，且有进位的话，那么后后面肯定是999，然后最后一位是0；第一位是1，那么push_back(0),然后第一位赋值为1；
// 标准答案
vector<int> plusOne1(vector<int> &digits) 
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i) 
    {
        if (digits[i] == 9) digits[i] = 0;
        else {
            digits[i] += 1;
            return digits; // 立马就返回了
        }
    }
    if (digits.front() == 0)  // 也可以这么写：if(digits.front==0) digits.insert(digits.begin(),1);
    {
        digits.push_back(0);
        digits[0]=1;
    }
    return digits;
}


int main()
{
    vector<int> nums = {1,1,1};
    plusOne(nums);
    for(auto i:nums)
    {
        cout<<i<<" ";
    }
    return 0;

}