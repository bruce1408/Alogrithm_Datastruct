/*682 BaseBall Game 
  使用函数stoi函数，将字符串转换成数字。
  */

#include<iostream>
#include<vector>
#include<numeric>
#include <string> 
using namespace std;

// int calPoints(vector<string>& ops);

class Solution
{
	public:
	int calPoints(vector<string>& ops) 
	{
		vector<int> rounds;
		for(int i = 0; i < ops.size(); i++)
		{
			if(ops[i] == "D")
				rounds.push_back(rounds.back() * 2);
			else if(ops[i] == "C")
				rounds.pop_back();
			else if(ops[i] == "+")
			{
				int size = rounds.size();
				rounds.push_back(rounds[size - 1] + rounds[size - 2]);
			}
			else
				rounds.push_back(stoi(ops[i]));
		}
		return accumulate(rounds.begin(), rounds.end(),0);
	}
	
};


int main()
{
    
    vector<string> ops{ "5","2","C","D","+" };
	Solution ss;
    cout<<ss.calPoints(ops)<<endl;
    return 0;

}









// int calPoints(vector<string>& ops)
// {
    // vector<int> temp;
    // int sum = 0;

    // for(int i = 0;i<ops.size();i++)
    // {
        // int score = 0;
        // if (ops[i] == "D")
		// {
			// score = temp.back() * 2;
            // sum += score;
		// }
        // else if (ops[i] == "C")
        // {
            // sum -= temp.back();
            // temp.pop_back();
            // continue;
        // }
        // else if (ops[i] == "+")
		// {
			// score = temp.back() + temp[temp.size() - 2];
			// sum += score;
		// }
        // else
            // sum+=score=stoi(ops[i]);
        // temp.push_back(score);
    // }

    // return sum;
// }















































