#include<iostream>
#include<string>
using namespace std;

/**
 * AcWing 763. 循环相克令
 * 循环相克令是一个两人玩的小游戏。
 * 令词为“猎人、狗熊、枪”，两人同时说出令词，同时做出一个动作——猎人的动作是双手叉腰;狗熊的动作是双手搭在胸前;枪的动作是双手举起呈手枪状。
 * 双方以此动作判定输赢，猎人赢枪、枪赢狗熊、狗熊赢猎人，动作相同则视为平局。现在给定你一系列的动作组合，请你判断游戏结果
 * 
 * 输入样例
 * 3
 * Hunter Gun
 * Bear Bear
 * Hunter Bear
 * 
 * 输出样例
 * Player1
 * Tie
 * Player2
*/
int gets(string s)
{
    int a;
    if(s=="Hunter") a = 0;
    else if(s=="Bear") a = 1;
    else a = 2;
    return a;
}


int main()
{
    int n;
    cout<<"请输入想要比较的几组数据：n:"<<endl;
    cin>>n;
    string x, y;
    while(n--)
    {
        cin>>x>>y;
        int a, b;
        a = gets(x), b = gets(y);
        if (a==b) cout<<"Tie"<<endl;
        else
        {
            if(a == (b+1)%3) cout<< "Player1" <<endl;
            else cout<<"Player2"<<endl;
        }   
    }
    return 0;
}