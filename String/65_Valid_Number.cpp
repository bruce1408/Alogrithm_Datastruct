#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isNumber(string s)
{
    //removing leading and trailing whitespaces
    int i = 0;
    while (s[i] == ' ')
        i++;
    if (i == s.size())
        return false;
    s = s.substr(i);
    reverse(s.begin(), s.end());
    i = 0;
    while (s[i] == ' ')
        i++;
    if (i == s.size())
        return false;
    s = s.substr(i);
    reverse(s.begin(), s.end());

    //begin FSA with state = 0, and stops if reached dead state = -1
    //  0 -> +/- , 1->digit , 2-> . , 3-> e
    vector<vector<int>> FSA = {{2, 3, 1, -1}, {-1, 4, -1, -1}, {-1, 3, 1, -1}, {-1, 3, 7, 5}, {-1, 4, -1, 5}, {6, 8, -1, -1}, {-1, 8, -1, -1}, {-1, 4, -1, 5}, {-1, 8, -1, -1}};
    int state = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-')
            state = FSA[state][0];
        else if (s[i] >= '0' && s[i] <= '9')
            state = FSA[state][1];
        else if (s[i] == '.')
            state = FSA[state][2];
        else if (s[i] == 'e')
            state = FSA[state][3];
        else
            return false;

        if (state == -1)
            return false;
    }
    return state == 3 || state == 7 || state == 4 || state == 8;
}

int main()
{
    string a = "abde";
    cout << isNumber(a) << endl;
}