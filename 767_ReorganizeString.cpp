/*------------- 767. Reorganize String ------------------
  有两种思路，一种是排序，还有一种是贪心算法。*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(int a,int b)
{
	return a>b;
}


// /* 这种解法没有排序，没有用堆。*/
// class Solution
// {
	// public:
	// string reorganizeString(string S)
	// {
		// vector<int> freq(26,0);
		// int m=0,pos=0;
		
		// for(int i=0;i<S.size();i++)// 统计字符次数
		// {
			// freq[S[i]-'a']++;
		// }
		
		// for(int i=0;i<26;i++)
		// {
			// if(freq[i]<=m)
				// continue;
			// m=freq[i],pos=i;
		// }
		
		// if(S.size()%2==0 && S.size()/2)
			// return "";
		// if(S.size()%2==0 && S.size()/2+1)
			// return "";
		// string res(S.size(),' ');
		// int cur=0,i=0;
		// for(i;i<S.size() && freq[pos]!=0;i+=2)
		// {
			// res[i]=pos+'a';
			// freq[pos]--;
		// }
		
		// for(i;i<S.size();i+=2)
		// {
			// while(freq[cur]==0)
				// cur++;
			// res[i]=cur+'a';
			// freq[cur]--;
		// }
		
		// for(i=1;i<S.size();i+=2)
		// {
			// while(freq[cur]==0)
				// cur++;
			// res[i]=cur+'a';
			// freq[cur]--;
		// }
	
		// return res;
	// }
// };





class Solution 
{
	public:
	string reorganizeString(string S)
	{
		int len = S.size();
		string ts = S;
		bool ans1 = true;
		for(int i=0;i<len;i++)
		{
			if(ts[i]==ts[i+1]) 
			{
				if(i == len-2) ans1 = false;
				for(int j=i+2;j<len;j++)
				{
					if(ts[j]!=ts[i] && ts[j]!=ts[i+1])
					{
						swap(ts[j], ts[i+1]);
						break;
					}
					if(j == len-1) {
						ans1 = false;
					}
				}
			}
		}
		string ts2 = ts;
		reverse(ts2.begin(), ts2.end());
		bool ans2 = true;
		for(int i=0;i<len;i++)
		{
			if(ts2[i]==ts2[i+1])
				{
					if(i == len-2) ans2 = false;
					for(int j=i+2;j<len;j++)
				{
					if(ts2[j]!=ts2[i] && ts2[j]!=ts2[i+1])
					{
						swap(ts2[j], ts2[i+1]);
						break;
					}
					if(j == len-1) 
					{
						ans2 = false;
					}
				}
			}
		}
		if(ans1)
		{
			return ts;
		}
		else if(ans2)
		{
			return ts2;
		}
		else
		{
			return "";
		}
	}
};



int main()
{
	
	// string str = "baabbccbb";
	string str = "bbbbb";
	
    int cnt[26]={};  
	int ll = str.size();
    for(int i=0;i<ll;i++)    
        cnt[str[i]-'a']++; 
        // cnt[str[i]]++; 
	
	// sort(cnt,cnt+256,comp);
	cout<<cnt[0]<<endl;
    for(int i=0;i<26;i++)//输出字符出现次数  
    {  
        if(cnt[i]!=0)  
        {
			// cout<<(char)i<<':'<<cnt[i]<<endl;   
			cout<<i<<':'<<cnt[i]<<endl;   
		}
    }
	
	Solution s;
	string ss = s.reorganizeString(str);
	cout<<ss<<endl;
	
	return 0;	
}































