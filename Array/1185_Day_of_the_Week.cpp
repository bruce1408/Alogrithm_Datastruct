#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * 给一个日期计算这个日期下是星期几
*/

int isLeap(int year)
{
    if((year%100!=0 && year%4==0) || (year%400==0))
    {
        return 1;
    }
    else return 0;
}
string dayOfTheWeek(int day, int month, int year)
{
    vector<string>da = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
     "Friday", "Saturday"};

    vector<int>monthDay = {31,28+isLeap(year),31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    for(int i=1970;i<year;i++)
    {
        sum+=isLeap(i)+365;
    }
    for(int i=1;i<month;i++)
    {
        sum+=monthDay[i-1];
    }
    sum+=day;
    return da[(sum+3)%7];
}

int main()
{
    cout<<dayOfTheWeek(31, 8, 2019)<<endl;
}