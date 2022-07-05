class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int maxi=0;
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) continue;
            if(nums[i]==nums[i+1]-1){
                count++;
                maxi=max(maxi,count);
            }
            else count=0;
        }
        return maxi+1;
    }
};