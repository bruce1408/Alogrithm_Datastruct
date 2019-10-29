#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/**
 * In a deck of cards, each card has an integer written on it.
 * Return true if and only if you can choose X >= 2 
 * such that it is possible to split the entire deck into 1 or more groups of cards, where:
 * Each group has exactly X cards.
 * All the cards in each group have the same integer.
 * 
 * Example 1:
 * Input: [1,2,3,4,4,3,2,1]
 * Output: true
 * Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
*/

/**
 * 方法 1，先排序，然后统计相同数字元素出现的次数，放到es数组中，
 * 然后遍历数组，让其每个数字和上一个数字求最大公约数，使用辗转相除法来做，
 * 最后的最大公约数如果大于1，那么就是返回true，否则，返回false；
*/
int gcd(int a, int b)
{
    while(b)
    {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

bool hasGroupsSizeX(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    int eachLength = deck.size();
    int i=0, j=i+1;
    vector<int>res;
    vector<int>temp;
    temp.push_back(deck[0]);
    while(i<eachLength && j<eachLength)
    {   
        
       if(deck[i]==deck[j] && j<eachLength)
       {
           temp.push_back(deck[j]);
           j++;
       }
       else{
           res.push_back(temp.size());
           temp.clear();
           temp.push_back(deck[j]);
           i=j;
           j = i+1;
       }
    }
    if(j==eachLength)
    {
        res.push_back(temp.size());
    }
    
    int firstLength = res[0];
    int result = 0;
    for(int i=0;i<res.size();i++)
    {
        result = gcd(result, res[i]);
    }
    return result > 1;
}


/**
 * 方法 2，
*/
bool hasGroupsSizeX2(vector<int>&deck)
{
    unordered_map<int, int>res;
    for(int i=0;i<deck.size();i++)
    {
        res[deck[i]]++;
    }
    int gcdNum = 0;
    for(auto x:res)
    {
        gcdNum = gcd(x.second, gcdNum);
    }
    return gcdNum>1;
}


int main()
{
    vector<int>res=  {1,1,2,2,2,2,2,2,3,3,3,3,3,3,3,3};
    cout<<hasGroupsSizeX2(res)<<endl;
}
