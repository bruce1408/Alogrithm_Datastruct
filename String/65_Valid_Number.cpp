#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/**
 * 方法 1,使用有限状态机,把所有情况分成几个状态,然后每个状态的操作用数字取值来表示,如果不满足这个取值那么返回的是-1,
 * 最后只要有-1就表示状态是错的,否则,其他状态都可以构成数字.
*/
bool isNumber(string s){
    //removing leading and trailing whitespaces
    int i=0;
    while(s[i]==' ') i++;
    if(i==s.size()) return false;
    s = s.substr(i);
    reverse(s.begin(),s.end());
    i=0;
    while(s[i]==' ') i++;
    if(i==s.size()) return false;
    s = s.substr(i);
    reverse(s.begin(),s.end());
    
    //begin FSA with state = 0, and stops if reached dead state = -1
    //  0 -> +/- , 1->digit , 2-> . , 3-> e
    vector<vector<int>> FSA = {
        {2,3,1,-1}, // 0
        {-1,4,-1,-1},  // 1
        {-1,3,1,-1},  // 2
        {-1,3,7,5},  // 3
        {-1,4,-1,5},  // 4
        {6,8,-1,-1},  // 5
        {-1,8,-1,-1},  // 6
        {-1,4,-1,5},  // 7
        {-1,8,-1,-1}};  //8
    int state = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+' || s[i]=='-') state = FSA[state][0];
        else if(s[i]>='0' && s[i]<='9') state = FSA[state][1];
        else if(s[i]=='.') state = FSA[state][2];
        else if(s[i]=='e') state = FSA[state][3];
        else return false;
        
        if(state == -1) return false;
    }
    return state==3 || state==7 || state==4 || state==8;    
}


/**
 * 方法 2,使用条件语句,也是最一般的写法
 * 首先,去掉收尾的空格符号,然后开始讨论,
 * 分成dot小数点, 正负号+/-号,数字,还有科学计数符号e
 * 首字符必须是数字或者是+/-符号,然后中间数字的话,e的前面的数字不能是+-符号,且之前没有出现e,
 * 如果当前符号是正负号,那么他前面的数字只能是e符号,
 * 如果当前的符号是逗号,那么他之前不能有逗号和e符号出现,否则返回false
 * 参考链接
 * https://leetcode.com/problems/valid-number/discuss/714425/C%2B%2B-Finite-State-Automata-(FSA)-with-Diagram
 * 最后判断最后一位,最后是数字返回true,最后是小数点的话,那么前面不能有小数点,e符号,且前面数字存在
*/

bool isNumber1(string s)
{
    int len = s.size();
    int left = 0, right = len - 1;
    bool eExisted = false;
    bool dotExisted = false;
    bool digitExisited = false;
    // Delete spaces in the front and end of string
    while (s[left] == ' ') ++left;
    while (s[right] == ' ') --right;
    // If only have one char and not digit, return false
    if (left >= right && (s[left] < '0' || s[left] > '9')) return false;
    //Process the first char
    if (s[left] == '.') dotExisted = true;
    else if (s[left] >= '0' && s[left] <= '9') digitExisited = true;
    else if (s[left] != '+' && s[left] != '-') return false;
    // Process the middle chars
    for (int i = left + 1; i <= right - 1; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9') digitExisited = true;
        else if (s[i] == 'e' || s[i] == 'E')
        { // e/E cannot follow +/-, must follow a digit
            if (!eExisted && s[i - 1] != '+' && s[i - 1] != '-' && digitExisited) eExisted = true;
            else return false;
        } 
        else if (s[i] == '+' || s[i] == '-') 
        { // +/- can only follow e/E
            if (s[i - 1] != 'e' && s[i - 1] != 'E') return false;                
        } 
        else if (s[i] == '.') 
        { // dot can only occur once and cannot occur after e/E
            if (!dotExisted && !eExisted) dotExisted = true;
            else return false;
        } 
        else return false;
    }
    // Process the last char, it can only be digit or dot, when is dot, there should be no dot and e/E before and must follow a digit
    if (s[right] >= '0' && s[right] <= '9') return true;
    else if (s[right] == '.' && !dotExisted && !eExisted && digitExisited) return true;
    else return false;
}

/**
 * 方法 2,优化方法 1代码
 * 按照数字,小数点,e,符号,其他情况分类讨论
 * 
 * numAfterE表示e后面是否有数字
 * 如果当前位置是空格而后面一位不为空格，但是之前有数字，小数点，自然底数或者符号出现时返回false。
 * 前位置是符号,那么之前以为必须是e或者是空格;
 * 如果当前位置是数字,那么数字对应的flag标记为true,且numafterE标记为true;
 * 如果当前位置是小数点,那么之前出现小数点或者是e,,返回false,否则标记dot为true;
 * 如果当前位置是自然底数e,那么他之前如果没有出现数字,或者已经出现了e,返回false,否则标记为true,numAfterE标记为false
 * 其他如好直接返回false
 * 最后返回num && numAfterE的结果即可
*/
bool isNumber2(string s) {
    bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') {
            if (i < n - 1 && s[i + 1] != ' ' && (num || dot || exp || sign)) return false;
        } 
        else if (s[i] == '+' || s[i] == '-') {
            if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') return false;
            sign = true;
        } 
        else if (s[i] >= '0' && s[i] <= '9') {
            num = true;
            numAfterE = true;
        } 
        else if (s[i] == '.') {
            if (dot || exp) return false;
            dot = true;
        } 
        else if (s[i] == 'e') {
            if (exp || !num) return false;
            exp = true;
            numAfterE = false;
        } 
        else return false;
    }
    return num && numAfterE;
}

int main()
{
    string s = "-0.98";
    cout<<isNumber2(s)<<endl;
}