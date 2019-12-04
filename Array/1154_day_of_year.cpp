#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * given a date, return the corresponding day of the week for that date.
 * The input is given as three integers representing the day, 
 * month and year respectively.Return the answer as one of the following values
 *  {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
 * Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.
 * 
 * Example 1:
 * Input: date = "2019-01-09"
 * Output: 9
 * 
 * Explanation: Given date is the 9th day of the year in 2019.
 * 给一个日期计算这个日期下是这一年的第几日
*/

/**
 * 方法 1，闰年是能被4整除且不能被100整除，或者是能被400整除。且1970年的1月1号是周四，
 * 最后总的日期要减去1，因为算的时候，第一天是星期天，然后在加上周四，对7求余数即可
 * 第一步，先算出从1971年距离当前年份的前一年总共有多少天，平年加365天，闰年加366天。
 * 第二步，再计算给的月份的前几个月的天数之和，闰年2月有29天。
 * 第三步，再加上给的天数减去1天，因为题目给的示例中星期天是第一天。
 * 第四步，将最后得到的天数再加上4天，因为1970年1月1日是星期4，然后对7取余。
*/
int isLeap(int year)
{
    if((year%100!=0 && year%4==0) || (year%400==0))
    {
        return 1;
    }
    else return 0;
}
int dayOfYear(string date)
{
    // vector<string>da = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
    //  "Friday", "Saturday"};

    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 7));
    int day = stoi(date.substr(8, 10));
    vector<int>monthDay = {31,28+isLeap(year),31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    for(int i=0;i<month-1;i++)
    {
        sum+=monthDay[i];
    }
    sum+=day;
    return sum;
}

int main()
{
    string date = "2019-01-09";
    cout<<dayOfYear(date)<<endl;
}