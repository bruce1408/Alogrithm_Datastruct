/*438. Find All Anagrams in a String

Input: s: "cbaebabacd" p: "abc"

Output: [0, 6]
*/


#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
	{
        if (s.empty()) return {};
        vector<int> res, m1(256, 0), m2(256, 0);
        for (int i = 0; i < p.size(); ++i)
		{
            ++m1[s[i]]; 
			++m2[p[i]];
		}
        if (m1 == m2) res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) 
		{
            ++m1[s[i]]; 
            --m1[s[i - p.size()]];
            if (m1 == m2) res.push_back(i - p.size() + 1);
        }
        return res;
    }
};


// vector<int> findAnagrams(string s, string p)
// {
	// int s_size = s.size();
	// int p_size = p.size();
	// if(s_size==0) return {};
	// vector<int> res, m1(256,0),m2(256,0);
	// for(int i=0;i<p_size;i++)
	// {
		// ++m1[s[i]];
		// ++m2[p[i]];
	// }
	// if(m1==m2) res.push_back(0);
	// for(int i=p_size;i<s_size;i++)
	// {
		// ++m1[s[i]];
		// --m1[s[i-p_size]];
		// if(m1==m2) res.push_back(i-p_size+1);
	// }
	// return res;	
// }


int main()
{
	
	string s="cbaebabacd";
	string t="abc";
	vector<int> res;
	Solution ss;

	res = ss.findAnagrams(s,t);
	for(auto i: res)
		cout<<i<<" ";
	return 0;
}














































