#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <list>
using namespace std;

/**
 * 关于容器erase的各种不同情况
 * 先说结论：
 * 在调用erase方法之前使用迭代器自加或者自减，如果是在erase方法之后使用的话
 * 那么原来的位置已经被删除，如果在旧的位置，则会出现异常。
 * 
 * 错误使用方法1：在调用erase方法之后使用“++”来获取下一个元素的位置，由于在调用erase方法以后，
 * 该元素的位置已经被删除，如果在根据这个旧的位置来获取下一个位置，则会出现异常。
 * 
*/

int main()
{
    list<int> tempList;
    for (int i = 0; i < 10; i++)
    {
        tempList.push_back(i);
    }
    list<int>::iterator iter;
    iter = tempList.begin();
    // cout << iter << endl;
    cout << *iter << endl;
    cout << tempList.back() << endl;
    int value = 8;
    for (iter = tempList.begin(); iter != tempList.end();)
    {
        if (*iter == value)
        {
            cout << "before :" << *iter << endl;
            iter = tempList.erase(iter); // 删除之前获取这个erase返回的下一个元素的位置
            // tempList.erase(iter); // 错误的使用方法
            cout << "after :" << *iter << endl;
        }
        else
        {
            iter++;
        }
    }
    for (auto i : tempList)
    {
        cout << i << " ";
    }
    cout << "size is: " << tempList.size() << endl;
    return 0;
}

/**
 * 在使用 vector、deque遍历删除元素时，也可以通过erase的返回值来获取下一个元素的位置
 * 1)对于关联容器(如map, set, multimap,multiset)，删除当前的iterator，
 * 仅仅会使当前的iterator失效，只要在erase时，递增当前iterator即可。
 * 这是因为map之类的容器，使用了红黑树来实现，插入、删除一个结点不会对其他结点造成影响。
 * 
 * 2)对于序列式容器(如vector,deque)，删除当前的iterator会使后面所有元素的iterator都失效。
 * 这是因为vetor,deque使用了连续分配的内存，删除一个元素导致后面所有的元素会向前移动一个位置。
 * 还好erase方法可以返回下一个有效的iterator。
 * 
 * 3)对于list来说，它使用了不连续分配的内存，并且它的erase方法也会返回下一个有效的iterator，
 * 因此上面两种方法都可以使用。
 * */
int main()
{
    vector<int>res(3,9);
    vector<int>::iterator iter;
    for(iter=res.begin();iter!=res.end())
    {
        if(*iter == 9)
        {
            iter = res.erase(iter);
        }
        else
        {
            iter++;
        }
    }
    return 0;
}

/**
 * vector
 * 内部数据结构：数组
 * 随机访问每个元素，所需要的时间为常量。
 * 在末尾增加或删除元素所需时间与元素数目无关，
 * 在中间或开头增加或删除元素所需时间随元素数目呈线性变化。
 * 可动态增加或减少元素，内存管理自动完成，但程序员可以使用reserve()成员函数来管理内存。
 * vector的迭代器在内存重新分配时将失效（它所指向的元素在该操作的前后不再相同）。
 * 当把超过capacity()-size()个元素插入vector中时，内存会重新分配，所有的迭代器都将失效；
 * 否则，指向当前元素以后的任何元素的迭代器都将失效。当删除元素时，
 * 指向被删除元素以后的任何元素的迭代器都将失效。
 * 
 * deque
 * 内部数据结构：数组。
 * 随机访问每个元素，所需要的时间为常量。
 * 在开头和末尾增加元素所需时间与元素数目无关，
 * 在中间增加或删除元素所需时间随元素数目呈线性变化。
 * 可动态增加或减少元素，内存管理自动完成，不提供用于内存管理的成员函数。
 * 增加任何元素都将使deque的迭代器失效。在deque的中间删除元素将使迭代器失效。
 * 在deque的头或尾删除元素时，只有指向该元素的迭代器失效。
 * 
 * list
 * 内部数据结构：双向环状链表。
 * 不能随机访问一个元素。
 * 可双向遍历。
 * 在开头、末尾和中间任何地方增加或删除元素所需时间都为常量。
 * 可动态增加或减少元素，内存管理自动完成。
 * 增加任何元素都不会使迭代器失效。删除元素时，除了指向当前被删除元素的迭代器外，
 * 其它迭代器都不会失效。
 * 
 * stack
 * 适配器，它可以将任意类型的序列容器转换为一个堆栈，一般使用deque作为支持的序列容器。
 * 元素只能后进先出（LIFO）。
 * 不能遍历整个stack。
 * 
 * queue
 * 它可以将任意类型的序列容器转换为一个队列，一般使用deque作为支持的序列容器。
 * 元素只能先进先出（FIFO）。
 * 不能遍历整个queue。
 * 
 * priority_queue
 * 适配器，它可以将任意类型的序列容器转换为一个优先级队列，一般使用vector作为底层存储方式。
 * 只能访问第一个元素，不能遍历整个priority_queue。
 * 第一个元素始终是优先级最高的一个元素
 * 
 * set
 * 键和值相等。
 * 键唯一。
 * 元素默认按升序排列。
 * 如果迭代器所指向的元素被删除，则该迭代器失效。其它任何增加、删除元素的操作都不会使迭代器失效
 * 
 * map
 * 键唯一。
 * 元素默认按键的升序排列。
 * 如果迭代器所指向的元素被删除，则该迭代器失效。其它任何增加、删除元素的操作都不会使迭代器失效。
 * */