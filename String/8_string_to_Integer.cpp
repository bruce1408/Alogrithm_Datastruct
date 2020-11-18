#include<iostream>
#include<sstream>
#include<string>
using namespace std;

/**
 * 方法 1、字符转数字 利用流方法简单
 * */ 
int strTonum(string a)
{
    int res;
    stringstream stream;
    stream<<a;
    stream>>res;
    return res;
}

/**
 * 方法 2、不是利用流，而是更加一般的方法； 按照几个条件去处理，空格->正负号->字符到数字->越界->输出

 * */
int strTonum2(string str)
{
    if(str.empty()) return 0;
    int i=0, res=0, sign=1, n=str.size();
    // 排除开头的空格
    while(str[i]==' '&& i<n) ++i;
    // 如果是有符号的，那么记录符号即可
    if(str[i]=='+'||str[i]=='-')
    {
        sign = (str[i++]=='+') ? 1:-1;
    }
    while(str[i]>='0'&&str[i]<='9'&&i<n)
    {
        // 考虑溢出问题。如果是这个数大于21xxxxxx467，那么就是取最大的那个越界边界。
        if(res>INT_MAX/10 || (res==INT_MAX/10 && str[i]-'0'>7))
        {
            return (sign==1)?INT_MAX:INT_MIN;
        }
        res = 10 * res + str[i++]-'0';
    }
    return res*sign;
}

/**
 * 方法 三、使用常规方法来做，先考虑空格，然后考虑正负号；
 * 按照几个条件去处理，空格->正负号->字符到数字->越界->输出
 * 然后在考虑是否越界
*/
int strTonum3(string str) 
{
    int k = 0; 
    //去空格
    while(k < str.size() && str[k] == ' ') k++;
    bool is_minus = false;
    long long num = 0;
    //判正负
    if(str[k] == '+') k++;
    else if(str[k] == '-') k++, is_minus = true;
    //字符变数字
    while(k < str.size() && str[k] >= '0' && str[k] <= '9')
    {
        num = num * 10 + str[k] - '0';
        k++;
    }
    //处理特例
    if(is_minus) num *= -1;
    if(num > INT64_MAX) num = INT64_MAX;
    if(num < INT64_MIN) num = INT64_MIN;
    return (int) num;
}


int main()
{
    string a = "     -9807";
    cout<<strTonum(a)<<endl;
    return 0;
}