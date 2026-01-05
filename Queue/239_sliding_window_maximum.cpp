/*
 * @Author: BruceCui
 * @version: 1.0.0
 * @Date: 2026-01-05 11:03:47
 * @LastEditors: BruceCui
 * @LastEditTime: 2026-01-05 12:55:35
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// 方法一：暴力法, 时间复杂度 O(n*k)
class Solution1 {
    public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    if (k == 1) return nums;
    vector<int> max_list;
    for (int i = 0; i <= nums.size() - k; i++) {
        int max_value = INT_MIN;
        for (int j = i; j < k + i; j++) {
            if (max_value < nums[j]) {
                max_value = nums[j];
            }
        }
        max_list.push_back(max_value);
    }

    return max_list;
    }
};


class Solution2 {
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        // 双端队列，存放的是数组的【下标】，而不是数值
        deque<int> dq; 
        
        for (int i = 0; i < nums.size(); i++) {
            
            // 1. 如果队列头部的下标已经滑出窗口范围，移除它
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // 2. 维护队列的单调性：
            // 如果当前进来的数字 nums[i] 比队列尾部的数字大，
            // 说明队列尾部的那个数字没用了（不可能成为最大值了），弹走它
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // 3. 把当前下标加入队列
            dq.push_back(i);
            
            // 4. 从第 k-1 个位置开始，队列头部就是当前窗口的最大值
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};

int main() {
    Solution2 s;
    vector<int> nums = {7,2,4};
    int k = 2;
    vector<int> res = s.maxSlidingWindow(nums, k);
    for (auto x : res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}