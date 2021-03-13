#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

class Soultion
{
public:
    priority_queue<long> small, large;

    double findMedian()
    {
        return small.size() > large.size() ? small.top() : 0.5 * (small.top() - large.top());
    }
    
    void addNum(int num)
    {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size())
        {
            small.push(-large.top());
            large.pop();
        }
    }

    
}