#include <iostream>
#include <vector>
using namespace std;

/**
 * 380 时间O(1)规模插入一个数字
 * 随机等概率访问每一个元素
 * 可以用hash常数级别插入数字，但是随机部分用数组vector来做 
*/
class RandomizedSet
{
public:
    vector<int> res;
    unordered_map<int, int> hash;
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (hash.count(val) == 0)
        {
            res.push_back(val);
            hash[val] = res.size() - 1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (hash.count(val) == 0)
        {
            return false;
        }
        else
        {
            int y = res.back();
            int px = hash[val], py = hash[y];
            swap(res[px], res[py]);
            swap(hash[val], hash[y]);
            res.pop_back();
            hash.erase(val);
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return res[rand() % res.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */