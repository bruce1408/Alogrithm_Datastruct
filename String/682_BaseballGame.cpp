#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

/**
 * 682 BaseBall Game 
 * 使用函数stoi函数，将字符串转换成数字。
 * */

int calPoints(vector<string> &ops)
{
	vector<int> rounds;
	for (int i = 0; i < ops.size(); i++)
	{
		if (ops[i] == "D")
			rounds.push_back(rounds.back() * 2);
		else if (ops[i] == "C")
			rounds.pop_back();
		else if (ops[i] == "+")
		{
			int size = rounds.size();
			rounds.push_back(rounds[size - 1] + rounds[size - 2]);
		}
		else
			rounds.push_back(stoi(ops[i]));
	}
	return accumulate(rounds.begin(), rounds.end(), 0);
}

int main()
{

	vector<string> ops{"5", "2", "C", "D", "+"};
	cout << calPoints(ops) << endl;
	return 0;
}
