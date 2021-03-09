/*402. Remove K Digits 移除k个位置之后，求剩下的最大的数字。
	比如是“001432219”*/

#include<iostream>
#include<string>
#include<stack>

using namespace std;


//自己写的版本
string removeKdigits(string num, int k) 
{
	stack<int>st;
	string res="";
	for(int i=0;i<num.size()-1;i++)
	{
		if(st.size()<k && num[i]>=num[i+1])
		{
			st.push(i);
		}	
	}
	while(st.size()!=0)
	{
		num.erase(st.top());
		st.pop();
	}
	return num;
}


// class Solution 
// {
	// public:
    // string removeKdigits(string num, int k) 
	// {
        // string res = "";
        // int n = num.size(), keep = n - k;
        // for (char c : num) 
		// {
            // while (k && res.size() && res.back() > c) 
			// {
                // res.pop_back();
                // --k;
            // }
            // res.push_back(c);
        // }
        // res.resize(keep);
        // while (!res.empty() && res[0] == '0') res.erase(res.begin());
        // return res.empty() ? "0" : res;
    // }
// };


//方法2，和503的思路很像。
class Solution
{
	public:
	string removeKdigits_bymyself(string num, int k) 
	{
		string res = "";
		int n = num.size();
		int keep = n-k;
		for(auto c:num)
		{
			while(k && res.back()>c && res.size())
			{
				res.pop_back();
				--k;	
			}
			res.push_back(c);
		}
		res.resize(keep);
		while(!res.empty() && res[0]=='0') res.erase(res.begin());
		return res.empty() ? "0" : res;
	}
	
};


int main()
{
	
	string num = "001432219";
	int k = 1;
	Solution ss;
	cout<<ss.removeKdigits_bymyself(num,k)<<endl;
	return 0;
}

















































