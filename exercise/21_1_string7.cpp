#include<iostream>
using namespace std;
/**
 * 有三个字符串S,S1,S2，其中，S长度不超过300，S1和S2的长度不超过10。
 * 现在，我们想要检测S1和S2是否同时在S中出现，且S1位于S2的左边，并在S中互不交叉（即，S1的右边界点在S2的左边界点的左侧）。
 * 计算满足上述条件的最大跨距（即，最大间隔距离：最右边的S2的起始点与最左边的S1的终止点之间的字符数目）。
 * 
 * 如果没有满足条件的S1，S2存在，则输出-1。
 * 例如，S = “abcd123ab888efghij45ef67kl”, S1=”ab”, S2=”ef”，其中，S1在S中出现了2次，S2也在S中出现了2次，最大跨距为：18。
 * 输入格式
 * 入共一行，包含三个字符串S,S1,S2，字符串之间用逗号隔开。
 * 数据保证三个字符串中不含空格和逗号。
 * 输出格式
 * 输出一个整数，表示最大跨距。
 * 如果没有满足条件的S1和S2存在，则输出-1.
*/



int main()
{
    string s, s1, s2;
    int index1=0, index2=0;
    getline(cin, s);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==',')
        {
            if(index1 == 0) index1 = i;
            else index2 = i;
        }
    }
    s1 = s.substr(index1+1, index2-index1-1);
    s2 = s.substr(index2+1, s.size());
    s = s.substr(0, index1);

    // cout<<s<<" "<<s1<<" "<<s2<<endl;
    int left = -1, right = -1;
    for(int j=0;j+s1.size()<s.size();j++)
    {
        int k=0;
        for(k=0;k<s1.size();k++)
        {
            if(s1[k] != s[k+j]) break;
        }
        if(k==s1.size())
        {
            left = j;
            break;
        }
    }

    for(int j=0;j+s2.size()<=s.size();j++)
    {
        int h=0;
        for(h=0;h<s2.size();h++)
        {
            if(s2[h] != s[h+j]) break;
        }
        if(h==s2.size() && j>=right)
        {
            right = j;
        }
    }
    // cout<<flag1<<" "<<flag2<<endl;
    if(left >=0 && right >=0 && left + s1.size() <= right)
    {
        cout<<right - left - s1.size()<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
}
    
    
// //方法一读取字符串的时候可以改进一下
// string s, s1, s2;
// char c;
// while(cin>>c, c!=',') s+=c;
// while(cin>>c, c!=',') s1+=c;
// while(cin>>c) s2 += c;

// // 或者是方法二
// string s, s1, s2;
// getline(cin, s, ',');
// getline(cin, s1, ',');
// getline(cin, s2,'\n')


// 方法二，简单写法，但是思路都一样
int maxdistance()
{
    string s, s1, s2;
    // char c;
    // while(cin>>c, c!=',') s+=c;
    // while(cin>>c, c!=',') s1+=c;
    // while(cin>>c) s2+=c;
    s = "aaaaaaaaaaaaaaaaaa", s1 = "b", s2="aa";
    if(s.size() < s1.size() || s.size() < s2.size()) cout<<"-1"<<endl;
    else
    {
        int left = 0;
        while(left + s1.size() <= s.size())
        {
            int k=0;
            while(k<s1.size())
            {
                if(s1[k] != s[k+left]) break;
                k++;
            }
            if(k==s1.size()) break;
            left++;
        }

        int right = s.size() - s2.size();

        while(right >= 0)
        {
            int k = 0;
            while(k<s2.size())
            {
                if(s[right + k] != s2[k]) break;
                k++;
            }
            if(k == s2.size()) break;
        }
        left += s1.size() - 1;
        cout<<left<<" "<<right<<endl;
        if (left >= right ) cout<<"-1"<<endl;
        else
        {
            cout<<right -left -1<<endl;
        }
        
    }

}


// 方法三
int maxdistance1()
{
    string A,B,C;
    getline(cin,A,',');
    getline(cin,B,',');
    getline(cin,C,'\n');
    int f,l;
    f=A.find(B)+B.size();//查找左边字符的位置
    l=A.rfind(C);//查找右边字符的位置(rfind从后向前查找第一个符合的字符串)
    //cout<<f<<" "<<l<<endl;
    if(A.find(B)==string::npos||A.rfind(C)==string::npos||l<f) //不满足条件的判断
        cout<<"-1"<<endl;
    else
        cout<<l-f<<endl;
    return 0;
}


// 方法四
int maxdistance4()
{

    string S,S1,S2;
    int i=0;
    char a;
    while(cin>>a)
    {
        if(a!=',')
        {
            if(i==0) S+=a;
            else if(i==1) S1+=a;
            else S2+=a;
        }
        else i++;
    }
    int s,s1,s2;
    s1=S.find(S1);
    s2=S.rfind(S2);
    if(s1 != -1 && s2 != -1 && (s1+S1.length()-1)<s2){
        cout<<s2-s1-S1.length()<<endl;
    }
    else cout<<"-1"<<endl;

}


int main()
{
    cout<<"maxdistance is: "<<maxdistance()<<endl;
}
