#include<iostream>
#include<string>
#include<vector>

using namespace std;

//单词翻转


// 单个单词进行翻转
string reverse_str(string s)
{
    int left = 0, right = s.size()-1;
    while(left < right)
    {
        swap(s[left++], s[right--]);
    }
    return s;
}


string cut_string(string &s)
{
  string temp = "", final_s = "";
    for(auto x: s)
    {
        if(x != ' ') {
            temp += x;
        }
        else{
            final_s += reverse_str(temp);
            final_s += ' ';
            temp = "";
        }
    }
    if (!temp.empty())
    {
        final_s += reverse_str(temp);
    }
    return final_s;
}


int main()
{
  string a;
  getline(cin, a);
  cout<<cut_string(a)<<endl;
}