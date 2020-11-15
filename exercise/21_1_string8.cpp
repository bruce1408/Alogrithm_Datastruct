#include<iostream>
#include<string>
using namespace std;

/**
 * 最长公共字符串后缀
 * 比如输入：
 * 输入格式
 * 由若干组输入组成。
 * 
 * 每组输入的第一行是一个整数N。
 * N为0时表示输入结束，否则后面会继续有N行输入，每行是一个字符串（字符串内不含空白符）。
 * 每个字符串的长度不超过200。
 * 输出格式
 * 共一行，为N个字符串的最长公共后缀（可能为空）。
 * 
 * 输入样例：
 * 3
 * baba
 * aba
 * cba
 * 2
 * aa
 * cc
 * 2
 * aa
 * a
 * 0
 * 输出样例：
 * ba
 * a
 * 
*/
int main()
{
    int n;
    while(cin>>n, n!=0)
    {
        string str[n], res="";
        int i=0, maxlen = 0;
        while(i<n)
        {
            string temp;
            cin>>temp;
            str[i++] = temp;
        }
        for(int i=str[0].size()-1; i>=0; i--)
        {
            int times = n-1;
            string perfix = str[0].substr(i, str[0].size());
            // cout<<"perfix: "<<perfix<<endl;
            for(int j=1; j<n; j++)
            {
                // cout<<"the str[j] is: "<<str[j]<<endl;
                for(int k=str[j].size()-1; k>=0; k--)
                {
                    if(str[j].substr(k, str[j].size()) == perfix)
                    {
                        times--;
                        if(maxlen < perfix.size() and times==0) 
                        {
                            maxlen = perfix.size();
                            res = perfix;
                        }
                    }                    
                }    
                // cout<<"times: "<<times<<endl;
                // if(times == 0) res = perfix;
                cout<<res<<endl;
            }
        }
        cout<<"res: "<<res<<endl;
    }

}