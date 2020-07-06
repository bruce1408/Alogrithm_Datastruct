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
*/

bool isNumber1(string s)
{
    
}


int main()
{
    string s = "abc";
    cout<<isNumber(s)<<endl;
}