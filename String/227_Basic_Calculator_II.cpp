#include<iostream>
#include<vector>
#include<string>
using namespace std;

stack<int> nums;
stack<char> op;
int calculate(string s) 
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ') continue;
        if(isdigit(s[i]))
        {
            int j = i;
            while(j<s.size() && isdigit(s[j]))
                j++;
            
            
        }
    }
}

int main()
{

}