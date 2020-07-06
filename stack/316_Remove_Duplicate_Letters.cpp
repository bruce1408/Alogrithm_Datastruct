#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Given a string which contains only lowercase letters, 
 * remove duplicate letters so that every letter appears once and only once.
 * You must make sure your result is the smallest in lexicographical order among all possible results.
 * 
 * Example 1:
 * Input: "bcabc"
 * Output: "abc"
*/

/**
 * 方法 1，
*/
string removeDuplicateLetters(string s)
{
    vector<int> m(256, 0);
    vector<int> visited(256, 0);
    string res = "";
    for (auto i : s)
    {
        ++m[i];
    }
    for (auto a : s)
    {
        --m[a];
        if (visited[a])
            continue;
        while (a < res.back() && m[res.back()])
        {
            visited[res.back()] = 0;
            res.pop_back();
        }
        res += a;
        visited[a] = 1;
    }
    return res.substr(1);
}

int main()
{
    string a = "bcabc";
    cout << removeDuplicateLetters(a) << endl;
}