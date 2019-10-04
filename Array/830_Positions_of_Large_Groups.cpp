#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * In a string S of lowercase letters,
 * these letters form consecutive groups of the same character.
 * For example, a string like S = "abbxxxxzyy" has the groups "a", 
 * "bb", "xxxx", "z" and "yy".Call a group large if it has 3 or more characters. 
 * We would like the starting and ending positions of every large group.
 * The final answer should be in lexicographic order.
 * 
 * Example 1:
 * Input: "abbxxxxzzy"
 * Output: [[3,6]]
 * Explanation: "xxxx" is the single large group with starting 3 and ending positions 6.
 * 给定一个字符串，然后找出连续重复出现次数大于等于3次的字符的起始位置和结束位置；
 */

vector<vector<int>> largeGroupPositions(string S)
{
    int left = 0, right = S.size();
    while(left+1<right)
    {
        int count =1;
        int index = left+1;
        int beginIndex = left, endIndex = left;
        if(S[left] == S[index])
        {
            count+=1;
            leftIndex = left;
            if(count>3)
            {
                endIndex = index;
            }
        }
        left++;

    }
}

int main()
{
    string str = "abbxxxxzyy";
    vector<vector<int>>res = (str);
    for(auto num:res)
    {
        for(auto i:num)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}