class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int curr_sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            curr_sum=max(curr_sum+nums[i],nums[i]);
            maxi=max(maxi,curr_sum);
        }
        return maxi;
    }
};