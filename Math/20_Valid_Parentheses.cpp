#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

/*
    括号匹配问题。用栈来解决，思路没问题，就是处理的时候，这个代码只能处理(),不能处理这种类型((。
    Example 1:
    Input: "()"
    Output: true

    Example 2:
    Input: "()[]{}"
    Output: true
*/ 
int flagnum(char s)
{
    int flag=0;
    if(s=='[' || s==']') flag=1;
    else if(s=='{'||s=='}') flag=2;
    else if(s=='('||s==')') flag=3;
    return  flag;

}
bool isValid(string s) 
{
    if(s.size()==0) return false;
    stack<char>mystack;
    char a = s[0];
    int flag = flagnum(a);
    cout<<flag<<endl;
    mystack.push(s[0]);
    for(int i=1;i<s.size();i++)
    {
        int curnum = flagnum(s[i]);
        if(flag==curnum && !mystack.empty())
        {
            mystack.pop();
            if(!mystack.empty()) flag = flagnum(mystack.top());
            // flag = flagnum(mystack.top());
        }
        else 
        {
            mystack.push(s[i]);
            flag = flagnum(s[i]);
        }
    }
    return mystack.empty()?true:false;
}



// 正确解法 这个是如果你的下一个开口向左的而且和上一个不匹配，那么一定是错误的
bool isValid1(string s) 
{
    // 几个边界条件
    if(s.size()==0) return true;
    else if(s.size()%2!=0) return false;
    else if(s[0]==')' || s[0]==']' || s[0]=='}') return false;

    stack<char> parentheses;
    for (int i = 0; i < s.size(); ++i) 
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') parentheses.push(s[i]);
        else 
        {
            // 上一个如果不是右开口，那么一定和左开口匹配，不匹配就是false；
            if (parentheses.empty()) return false;
            if (s[i] == ')' && parentheses.top() != '(') return false;
            if (s[i] == ']' && parentheses.top() != '[') return false;
            if (s[i] == '}' && parentheses.top() != '{') return false;
            parentheses.pop();
        }
    }
    return parentheses.empty();
}
int main()
{
    string a = "((";
//    cout<< flagnum(a[0]);
    cout<<isValid(a);
    return 0;
}