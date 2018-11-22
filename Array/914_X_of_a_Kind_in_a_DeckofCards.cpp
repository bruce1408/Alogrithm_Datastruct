#include<iostream>
#include<vector>
using namespace std;

// flower 可以放花的个数
// 没看懂，重做吧
bool canPlaceFlowers(vector<int>& flowerbed, int n) 
{
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    for (int i = 1; i < flowerbed.size() - 1; ++i) 
    {
        if (n == 0) return true;
        if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
            --n;
            ++i;
        }
    }
    return n <= 0;
}

int main()
{
    vector<int> res = {1,1,2,2,3,3,4,4,2,2,1,1};


    return 0;
}