#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
    字符串压缩，
    Input:
    ["a","a","b","b","c","c","c]

    Output:
    ["a","2","b","2","c","3"]
*/
// int compress(vector<char>& chars) 
// {
//     int n = chars.size();
//     int cur = 0;
//     for(int i=0; i<n; i++)
//     {
//         int j=i;
//         while(j<n-1 && )
//     }
// }


int compress(vector<char>& chars) 
{
    const int n = chars.size();
    int p = 0;
    for (int i = 1; i <= n; ++i) 
    {
        int count = 1;
        while (i < n && chars[i] == chars[i - 1]) { ++i; ++count; }
        chars[p++] = chars[i - 1];
        if (count == 1) continue;
        for (char c : to_string(count))
        chars[p++] = c;
    }
    for(auto i:chars)
    {
        cout<<i<<" ";
    }
    return p;
}


int main()
{
    vector<char>res = {'a','a','a','b','b'};
    cout<<compress(res);
    // for(auto i:res)
    // {
    //     cout<<i<<endl;
    // }
}