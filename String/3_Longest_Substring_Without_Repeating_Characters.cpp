/*3. Longest Substring Without Repeating Characters

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

给一个字符串，输出的是没有重复的自传的长度。


*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;


// 解法有一点问题，但是确实是要给一个左指针，指向开始计数的开端
// int lengthOfLongestSubstring(string s)
// {
// 	int max=0;
// 	int count =0;
// 	char left,right;
// 	left = s[0];
// 	for(int i=0;i<s.size();i++) 
// 	{
// 		right = s[i+1];
// 		if(left!=right && right!=s[i])
// 		{
// 			count+=1;
// 			cout<<count<<endl;
// 		}
// 		else
// 		{
// 			left = right;
// 			max = (max>=count)? max:count;
// 			count=0;
// 		}
// 	}
// 	return max;		
// }


// 正确的解法
int lengthOfLongestSubstring(string s) {
        int m[256] = {0}, res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 0 || m[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        return res;
    }

int main()
{
	
	string s = "abcabcbb";
	cout<<lengthOfLongestSubstring(s)<<endl;
	return 0;

}
