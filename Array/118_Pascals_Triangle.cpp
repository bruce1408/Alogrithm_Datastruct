#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;


// 打印杨辉三角
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res(numRows, vector<int>());
    for(int i=0;i<numRows;i++)
    {
        res[i].resize(i+1,1);
        for(int j=1;j<i;j++)
        {
            res[i][j] = res[i-1][j-1] + res[i-1][j]; 
        }
    }
    return res;
}

// 时间虽然慢，但是很好理解
vector<vector<int>> generate1(int numRows) 
{
    vector<vector<int>> ans;
    
    if (!numRows)
        return ans;
    
    vector<int> row(1, 1);
    ans.push_back(row);
    for (int r = 2; r <= numRows; ++r) {
        vector<int> nextRow(row.size()+1);
        nextRow[0] = nextRow[nextRow.size()-1] = 1;
        for (int i = 1; i < nextRow.size()-1; ++i)
            nextRow[i] = row[i] + row[i-1];
        ans.push_back(nextRow);
        row = nextRow;
    }
    return ans;
}

int main()
{
    int num = 5;
    generate(num);
}
