#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/**
 * pair 是一种简单的容器，可以存放两个数据类型完全不同的元素；例如
 * pair (data_type1, data_type2) Pair_name;
 * 得到pair用first，和 second来get到对应的数据
 * 
*/
int main()
{
    // pair 初始化，如果没有复制的话，那么第一个数就是数字0，第二个数是字符null空
    pair<int, char> PAIR1; 
    cout << PAIR1.second << endl;
    PAIR1.first = 100;
    PAIR1.second = 'G';
    pair<string, double> PAIR2("GeeksForGeeks", 1.23);

    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;
    
    // make_pair 不需要写数据类型，直接可以创建一个pair对
    pair <string, double> PAIR3 ; 
    PAIR3 = make_pair("GeeksForGeeks is Best", 4.56); 

    return 0;
}