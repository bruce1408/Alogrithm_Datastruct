/**
 * 381 在O(1)时间删除，插入，得到随机数组元素
 * 可以插入重复元素，所以使用两个hash来保存
*/
class RandomizedCollection
{
public:
    vector<int> res;
    unordered_map<int, unordered_set<int>> hash;
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        bool flag = hash[val].empty();
        res.push_back(val);
        hash[val].insert(res.size() - 1);
        return flag;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        if (hash[val].size())
        {
            // 删除的时候，还是把删除的位置和最后一个交换，但是因为有重复元素，所以删除第一个重复的位置即可；核心就是交换之后相应的位置也要交换，否则不成立
            int py = res.size() - 1, y = res.back(), px = *hash[val].begin();
            // 首先是数组进行交换
            swap(res[py], res[px]);
            // 删除的元素中把首次出现的位置删除，然后插入最后一个元素的位置
            hash[val].erase(px), hash[val].insert(py);
            // 最后一个元素删除它出现的位置，插入val首次出现的位置
            hash[y].erase(py), hash[y].insert(px);
            // res删除最后一个元素
            res.pop_back();
            // 同时最后一个位置也删除
            hash[val].erase(py);
            return true;
        }
        else
            return false;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return res[rand() % res.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */