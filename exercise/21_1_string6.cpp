#include<iostream>
using namespace std;

/**
 * 777 字符串乘方
 * 
 * 给定两个字符串a和b,我们定义a*b为他们的连接。
 * 例如，如果a=”abc” 而b=”def”， 则a*b=”abcdef”。
 * 如果我们将连接考虑成乘法，一个非负整数的乘方将用一种通常的方式定义：a0=””(空字符串)，a(n+1)=a∗(an)。
 * 输入格式
 * 输入包含多组测试样例，每组测试样例占一行。
 * 每组样例包含一个字符串s，s的长度不超过100。
 * 最后的测试样例后面将是一个点号作为一行。
 * 
 * 输出格式
 * 对于每一个s，你需要输出最大的n，使得存在一个字符串a，让s=an。
 * 输入样例：
 * abcd
 * aaaa
 * ababab
 * .
 * 
 * 输出样例：
 * 1
 * 4
 * 3
*/

// int main()
// {
//     string s1;
//     while(cin>>s1)
//     {
//         int flag = 0;
//         if(s1[0] == '.') break;
//         int len = s1.size();
//         for(int i=1; i<len;i++)
//         {
//             flag=0;
//             if(len%i !=0) continue;
//             for(int j=0;j<len;j++)
//             {
//                 if(s1[j] != s1[j%i])
//                 {
//                     flag = 1;
//                     break;
//                 }
//                 if(!flag) {
//                     cout<<len/i<<endl;
//                     break;
//                 }
//             }
//         }
//         if(flag) cout<<"-1"<<endl;
//     }
//     cout<<endl;

// }


int main()
{
    string s1;
    while(cin>>s1)
    {
        if(s1[0] == '.') break;
        int len = s1.size();
        for(int i=0;i<len;i++)
        {
            int times = len-i;
            if(len%(i+1) != 0) continue;
            string temp="";
            int j=0;
            for(j=0;j<=i;j++)
            {
                temp+=s1[j];                
            }
            // temp = s1.substr(0, i);
            string res="";
            for(int t=0;t<len/(i+1);t++)
            {
                res+=temp;
            }
            cout<<"class res: "<<res<<endl;
            if(res == s1 )
            {
                cout<<"maxtimes: "<<len/(i+1)<<endl;
                break;
            }
        }
    }
}


//更加简单的写法
int main()
{
    string s1;
    while(cin>>s1)
    {
        if(s1[0] == '.') break;
        int len = s1.size();
        for(int i=0;i<len;i++)
        {
            if(len%(i+1) != 0) continue;
            string temp="";
            temp = s1.substr(0, i);
            string res="";
            for(int t=0;t<len/(i+1);t++)
            {
                res+=temp;
            }
            cout<<"class res: "<<res<<endl;
            if(res == s1 )
            {
                cout<<"maxtimes: "<<len/(i+1)<<endl;
                break;
            }
        }
    }
}