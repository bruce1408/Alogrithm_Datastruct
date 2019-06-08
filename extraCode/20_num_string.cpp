#include<iostream>
#include<string>
using namespace std;

/**
 * 题目： 表示数字的字符串
 * 方法 根据要求来写边界条件
 * 思路：
 * 遍历字符串，如果是出现了e，那么判断不能同时存在两个e或者e不能是最后一个数
 * 如果出现了符号+或者是-，那么如果是第二次出现，那么必须接在e的后面，如果是第一次出现，而且不在开头
 * 位置，那么前面一定要有e，也就是第一次和第二次出现前面都要有e，但是第一次的位置不能是在首位置；
 * 如果出现了小数点，那么只能出现一次小数点，且e后面不能出现小数点
 * 如果是数字，那么不能小于0或者是大于9； 
 * */

bool isNumeric(string s)
{
    if(s.empty()) return false;
    bool hasE = false, decP = false, sign = false;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i]=='e' || s[i]=='E') // 第一种情况，如果出现了e，那么e不能在最后，前面不能有e，而且i不能是首位置元素，例如e2；
        {
            if(hasE || i==s.size()-1 || !i) return false;
            hasE = true;
        }
        else if(s[i]=='-' || s[i]=='+')
        {
            // 第二次出现了符号，但是前面不是e
            if(sign && s[i-1]!='e' && s[i-1]!='E' ) return false; 
            // 第一次出现符号，且不在开头位置，那么必须前面接e
            if(!sign && i>0 && s[i-1]!='e' &&s[i-1]!='E') return false;
            sign = true;
        }
        else if(s[i]=='.')
        {
            if(hasE || decP) return false; // 前面有e或者已经有一个小数点，那么返回false
            decP = true;
        }
        else if(s[i]<'0' || s[i]>'9') return false;
    }
    return true;
}
// bool isNumeric(string s) {
//     int i = 0;
//     while (i < s.size() && s[i] == ' ') i ++ ;
//     int j = s.size() - 1;
//     while (j >= 0 && s[j] == ' ') j -- ;
//     if (i > j) return false;
//     s = s.substr(i, j - i + 1);

//     if (s[0] == '-' || s[0] == '+') s = s.substr(1);
//     if (s.empty() || s[0] == '.' && s.size() == 1) return false;

//     int dot = 0, e = 0;
//     for (int i = 0; i < s.size(); i ++ )
//     {
//         if (s[i] >= '0' && s[i] <= '9');
//         else if (s[i] == '.')
//         {
//             dot ++ ;
//             if (e || dot > 1) return false;
//         }
//         else if (s[i] == 'e' || s[i] == 'E')
//         {
//             e ++ ;
//             if (i + 1 == s.size() || !i || e > 1 || i == 1 && s[0] == '.') return false;
//             if (s[i + 1] == '+' || s[i + 1] == '-')
//             {
//                 if (i + 2 == s.size()) return false;
//                 i ++ ;
//             }
//         }
//         else return false;
//     }
//     return true;
// }

int main()
{
    cout << isNumeric("100") << endl; 
    cout << isNumeric("123.45e+6") << endl;
    cout << isNumeric("+500") << endl;
    cout << isNumeric("5e2") << endl;
    cout << isNumeric("3.1416") << endl;
    cout << isNumeric("600.") << endl;
    cout << isNumeric("-.123") << endl;
    cout << isNumeric("23") <<endl;
 
    //False
    cout << "---------------------" << endl;
    cout << isNumeric("1a23") << endl;
    cout << isNumeric("12e") << endl;
    cout << isNumeric("1+23") << endl;
    cout << isNumeric("1.2.3") << endl;
    cout << isNumeric("10e10e") << endl;
    cout << isNumeric("e1") << endl;
    cout << isNumeric("e33") <<endl;
    cout << isNumeric("") << endl;
}

