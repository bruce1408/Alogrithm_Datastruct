#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

// string reverse(string &res)
// {
//     string str = "";
//     for(int i=res.size()-1;i>=0;i--)
//     {
//         str+=res[i];
//     }
//     return str;
// }
string convertToTitle(int n) 
{
    /*
        输入数字，对应的输出是excel的列
        先减减，然后求余，这个时候输出的顺序是反着的
    */
    string res = "";
    while(n)
    {
        n--;
        char str = (char)(n%26 + 'A');
        n = n/26;
        res += str;
    }
    reverse(res.begin(),res.end());
    return res;
    // cout<<"main: "<<res<<endl;
    // return res;
}

int main()
{
    cout<<convertToTitle(28);
    return 0;
}