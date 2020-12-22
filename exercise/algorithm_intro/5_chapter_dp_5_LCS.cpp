#include <iostream>
#include <string>
using namespace std;

/**
 * 最长公共子序列 LCS(longest common subsequence)
 * 给定两个字符串；A和B，求一个字符串，使得字符串是A和B的最长公共部分；
 * 
*/

string getcom(string a, string b)
{
    int n1 = a.size(), n2 = b.size();
    int i1=0, i2= 0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            string temp;
            int cnt = 0;
            if(a[i]==b[j])
            {
                for(int k = j+1; k<n2; k++)
                {
                    
                }
            }
        }
    }

}
int main()
{
    string a = "sadstory", b = "asminsorry";
    cout<<getcom(a, b)<<endl;

}