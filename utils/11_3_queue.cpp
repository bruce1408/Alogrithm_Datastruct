// #include<iostream>
// #include<vector>
// #include<queue>
// #include<deque>
// using namespace std;
// /**
//  * CPP code to illustrate
//  * Queue in Standard Template Library (STL)
//  * 队列，先进先出
// */
// void showq(queue <int> gq)
// {
//     queue <int> g = gq;
//     while (!g.empty())
//     {
//         cout << '\t' << g.front();
//         g.pop();
//     }
//     cout << '\n';
// }

// int main()
// {
//     queue <int> gquiz;
//     gquiz.push(10);
//     gquiz.push(20);
//     gquiz.push(30);
//     cout << "The queue gquiz is : ";
//     showq(gquiz);
//     cout << "\ngquiz.size() : " << gquiz.size();
//     cout << "\ngquiz.front() : " << gquiz.front();
//     cout << "\ngquiz.back() : " << gquiz.back();
//     cout << "\ngquiz.pop() : ";
//     gquiz.pop();
//     showq(gquiz);
//     return 0;
// }

#include <deque>
#include <iostream>
#include <vector>
using namespace std;
/**
 * 双端队列，两端元素都可以进行添加和删除，不像vector一样
 * 会把所有的对象保存在一个连续的内存块中，而是多个连续内存块映射
 * deque的内存区块不再被使用时，会被释放
 * 最好采用deque的情形如下：
 * 
 * 1、需要在两端插入和删除元素。
 * 2、无需引用容器内的元素。
 * 3、要求容器释放不再使用的元素。
*/

// int main()
// {
//     deque<int> mydeque;
//     // 1 2 3 4 5
//     for (int i = 1; i < 6; i++)
//         mydeque.push_back(i);
//     deque<int>::iterator it = mydeque.begin();
//     ++it;
//     // 1 10 2 3 4 5
//     it = mydeque.insert(it, 10);
//     // "it" now points to the newly inserted 10
//     // 1 20 20 10 2 3 4 5
//     mydeque.insert(it, 2, 20);
//     // "it" no longer valid!
//     it = mydeque.begin() + 2;
//     vector<int> myvector(2, 30);
//     cout << myvector.size() << endl;
//     mydeque.insert(it, myvector.begin(), myvector.end());
//     cout << "mydeque contains:";
//     for (it = mydeque.begin(); it != mydeque.end(); ++it)
//         cout << ' ' << *it;
//     cout << '\n';
//     return 0;
// }

#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> a;
    for (int i = 0; i < 5; i++)
        a.push_back(i);
    deque<int>::iterator it;
    it = a.begin();
    for (; it != a.end(); it++)
    {
        cout << *it << endl;
        a.erase(it);
    }
    return 0;
}
