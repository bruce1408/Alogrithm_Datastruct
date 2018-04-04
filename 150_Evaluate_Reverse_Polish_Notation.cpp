/*150. Evaluate Reverse Polish Notation 大话数据结构 中缀表达式*/
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;


//方法1
int evalRPN(vector<string>& tokens)
{
	stack<int> s;
	if (tokens.size() == 1) return atoi(tokens[0].c_str());
	for(int i=0;i<tokens.size();i++)
	{
		if(tokens[i]!="+" && tokens[i]!="-" &&tokens[i]!="*" &&tokens[i]!="/")
		{
			s.push(stoi(tokens[i]));		
		}
		else
		{
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			if(tokens[i]=="+") s.push(b+a);
			if(tokens[i]=="-") s.push(b-a);
			if(tokens[i]=="*") s.push(b*a);
			if(tokens[i]=="/") s.push(b/a);
		
		}
		
	}
	return s.top();
	
}



//方法2 采用switch case函数
class Solution 
{
	public:
    int evalRPN(vector<string>& tokens) 
	{
        stack<int> opStack;
        for (int i = 0; i < tokens.size(); i++) 
		{
            string curOp = tokens[i];
            if (curOp == "+" || curOp == "-" || curOp == "*" || curOp == "/") 
			{
                int op2 = opStack.top();
                opStack.pop();
                int op1 = opStack.top();
                opStack.pop();
                char curop = curOp[0];
                switch (curop) 
				{
                    case '+':
                        opStack.push(op1 + op2);
                        break;
                    case '-':
                        opStack.push(op1 - op2);
                        break;
                    case '*':
                        opStack.push(op1 * op2);
                        break;
                    case '/':
                        opStack.push(op1 / op2);
                        break;
                    default:
                        break;
                }
            } 
			else 
			{
                opStack.push(stoi(curOp));
            }
        }
        return opStack.top();
    }
};



//方法3：递归
class Solution 
{
	public:
    int evalRPN(vector<string>& tokens) 
	{
        int op = tokens.size() - 1;
        return helper(tokens, op);
    }
    int helper(vector<string>& tokens, int& op) 
	{
        string s = tokens[op];
        if (s == "+" || s == "-" || s == "*" || s == "/") 
		{
            int v2 = helper(tokens, --op);
            int v1 = helper(tokens, --op);
            if (s == "+") return v1 + v2;
            else if (s == "-") return v1 - v2;
            else if (s == "*") return v1 * v2;
            else return v1 / v2;
        } 
		else 
		{
            return stoi(s);
        }
    }
};

int main()
{
	vector<string> num = {"2", "1", "+", "3", "*"};
	cout<<evalRPN(num);
	return 0;
	
}




























































