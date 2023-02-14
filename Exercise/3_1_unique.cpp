#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

/**
 * unique并不是真正的去重，而是把未重复的数字排到前面，把重复的数字放到后面而已，原来数组的
 * 大小并没有改变；而且它是相邻的数字去重，最好是先排序然后去重
 * 而erase是真正的去重，直接删除原来的重复数字即可
*/
int main()
{
    //cout<<"Illustrating the generic unique algorithm."<<endl;
    const int N = 11;
    vector<int> vector1 = {1, 2, 0, 3, 3, 0, 7, 7, 7, 0, 8};

    vector<int>::iterator new_end;
    new_end = unique(vector1.begin(), vector1.end()); //"删除"相邻的重复元素
    assert(vector1.size() == N);
    for (auto i : vector1)
    {
        cout << i << " ";
    }
    cout << endl;

    vector1.erase(new_end, vector1.end()); //删除（真正的删除）重复的元素
    copy(vector1.begin(), vector1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}