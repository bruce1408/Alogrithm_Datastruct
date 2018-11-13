bool checkPossibility(vector<int>& nums) {
    int cnt=1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>nums[i+1])
        {
            if(i==0) nums[i] = nums[i+1];
            else
            {
                if(nums[i-1]<nums[i]) nums[i] = nums[i+1];
                if(nums[i-1]>nums[i]) nums[i] = nums[i-1];
            }
            
            cnt--;
        }
    }
    return cnt<0?false:true;
}