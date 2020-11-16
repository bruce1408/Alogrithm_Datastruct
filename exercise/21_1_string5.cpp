#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "hellohello", s2 = "llo";
    // for(int i=0;i<s1.size();i++)
    // {
    //     s1 = s1.substr(1) + s1[0];
    //     cout<<s1<<endl;
    // }
    cout << s1.find(s2) << endl;
}