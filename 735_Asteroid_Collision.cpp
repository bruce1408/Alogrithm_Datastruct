/*735. Asteroid Collision 小行星碰撞题目
	asteroids = [5, 10, -5]
	Output: [5, 10]
	正好表示同向，负号表示反向。大的消小的
*/

//  这个和503 基本都是一个套路
#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;


// 方法1
vector<int> asteroidCollision(vector<int>& asteroids)
{
	int n = asteroids.size();
	
	stack<int>s;
	for(int i=0;i<n;i++)
	{
		while(!s.empty() && asteroids[i]<0 &&s.top()>0)
		{
			if(s.top()<abs(asteroids[i]))   //判断是否是小于这个数
				s.pop();
				
			else if(s.top()==abs(asteroids[i]))//如果两个数相等就去掉栈的数字
			{
				s.pop();
				i++;       //元素加1，和下一个比较。
			}
			else
				i++;       //比较下一个[10,10,-5]
		}
		if(i<n)  //满足条件就入栈，这里是一个套路：如果不加判断，都会入栈
			s.push(asteroids[i]);
	}
	
	
	
	vector<int>res(s.size());         //把栈里的元素放到容器中去
	for(int j=s.size()-1;j>=0;j--)
	{
		res[j] = s.top();
		s.pop();
	}
	return res;
}


// 方法2：leetcode时间复杂度最少的方法
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) 
	{
        vector<int> s; // use vector to simulate stack.
        for (int i : a) 
		{
            while (!s.empty() && s.back() > 0 && s.back() < -i)
                s.pop_back();
                //^while top element gets lashed out by an Opposite Asteroid which is of Higher Value
            	//Eg. top([5, 10]) < -(-15) -> Pop Until Opposite asteroid is lashed out by Stack Top
            if (s.empty() || i > 0 || s.back() < 0)
                s.push_back(i);
            	//^ If it's empty or if AST is greater value or Stack top is of Lesser Value -> Keep pushing
            else if (i < 0 && s.back() == -i)//when TOP and AST are Equal Eg. top([5, 10]) == -(-10) -> Pop
                s.pop_back();
        }
        return s;
    }
};



int main()
{
	vector<int> num = {1,1,-1,-2};
	vector<int> res;
	res = asteroidCollision(num);
	for(auto i: res)
		cout<<i<<" ";
	return 0;	
}


























































