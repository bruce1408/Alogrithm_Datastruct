#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

/**
 * We have two special characters. 
 * The first character can be represented by one bit 0.
 *  The second character can be represented by two bits 
 * (10 or 11).Now given a string represented by several 
 * bits. Return whether the last character 
 * must be a one-bit character or not. 
 * The given string will always end with a zero.
 * 
 * Example 1:
 * Input: 
 * bits = [1, 0, 0]
 * Output: True
 * Explanation: 
 * The only way to decode it is two-bit character 
 * and one-bit character. So the last character is 
 * one-bit character.
 * 
 * Example 2:
 * Input: 
 * bits = [1, 1, 1, 0]
 * Output: False
 * Explanation: 
 * The only way to decode it is two-bit character 
 * and two-bit character. So the last character is NOT 
 * one-bit character.
 * 
 * 给定一个数组，由1和0组成，这个数组有
 * 两种特殊的字符，第一种就是 10 or 11两位字符的情况来表示 ，
 * 还有一种是 0 来表示该单字符。现在给定一个数组包含0和1，是否可以
 * 正确的分割，使得最后一个字符是单个字符。
*/

/**
 * 方法 1如果是遇到1的数组，那么肯定是两个字符，这个时候i+=2,跳2格，否则跳1格，然后给两个bool型变量判断，如果最后结束的时候，看
 * 哪种布尔类型是true即可。题目说最后一位一定是0，不用判断，但是
 * 此处还是判断了最后一位。
*/
bool isOneBitCharacter(vector<int>& bits) {
    int len = bits.size();
    bool bitOne = false, bitTwo = false; 
    for (int i=0; i<len;)
    {
        if(bits[i]==1)
        {
            i+=2;
            bitTwo = true;
            bitOne = false;
        }
        else 
        {
            i+=1;
            bitOne = true;
            bitTwo = false;
        }
    }
    return bitOne? true:false;
}

/**
 * 方法 2 和上面方法1的思路一样，就是写法有稍微不同之处，
 * 对于最后一位不用再判断。
*/
bool isOneBitCharacter1(vector<int>& bits) {
    int len = bits.size(), i = 0;
    while(i<len-1) // 不再判断最后一位
    {
        if(bits[i]==0) i++;
        else i+=2;
    }
    return i==len-1;
}

/**
 * 方法 3递归算法，如果某一位是0的话，那么就返回下一位到结束的整个
 * 数组，如果是 1的话返回i+2到结束的整个数组位置,递归的时候
 * 需要新建一个数组t
*/
bool isOneBitCharacter2(vector<int>& bits) 
{
    if(bits.empty()) return false;
    if(bits.size()==1) return bits[0]==0;

    vector<int>t;
    if(bits[0]==0) 
    {
        t = vector<int>(bits.begin()+1, bits.end());
    }
    else
    {
        t = vector<int>(bits.begin()+2, bits.end()); 
    } 
    return isOneBitCharacter2(t);
}

/**
 * 方法 4 和方法 3类似，但是不需要新建一个数组t，而是递归的老套路
 * 用一个helper函数来写。
*/
bool helper(vector<int>&bits, int index)
{
    if(index==bits.size()) return false; // 两个边界条件；
    if(index==bits.size()-1) return bits[index]==0;

    if(bits[index]==0) return helper(bits, index+1);
    return helper(bits, index+2);
}

bool isOneBitCharacter2(vector<int>& bits) 
{
    return helper(bits, 0);
}


