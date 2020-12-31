#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 38 Count and Say 计数和读法
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 给定一个数，然后按照读法来学，1表示1个1，写作11，
 * 11是2个1，写作21， 21是1个2 1个1，写成1211....
 * 每次写的都是前一次的值 
*/

string countAndSay(int n)
{
    string temp = "1";
    for (int i = 0; i < n - 1; i++)
    {
        string s;
        for (int j = 0; j < temp.size(); j++)
        {
            int cnt = 1;
            while (j + 1 < temp.size() && temp[j] == temp[j + 1])
            {
                cnt++;
                j++;
            }
            s += to_string(cnt) + temp[j];
        }
        temp = s;
    }
    return temp;
}

int main()
{
    cout << countAndSay(6) << endl;
}