#include<iostream>
#include<vector>
using namespace std;

int duplicateInArray(vector<int>& nums) {
    if(nums.empty()) return -1;
    
    int l = 1, r = nums.size()-1;
    while(l < r){
        int mid = (l + r) >> 1, s = 0;
        for(auto x: nums){
            s+=(x >= l && x <=mid);
        }
        if(s > mid - l + 1) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
    vector<int>nums = {2,3,5,4,3,2,6,7};
    cout<<duplicateInArray(nums)<<endl;
}