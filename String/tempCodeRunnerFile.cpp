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