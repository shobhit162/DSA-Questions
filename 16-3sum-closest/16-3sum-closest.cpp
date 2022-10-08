class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int close=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int cursum=nums[i]+nums[j]+nums[k];
                if(cursum==target) return cursum;
                if(abs(target-cursum)<abs(target-close))
                    close=cursum;
                if(cursum<target)
                    j++;
                else
                    k--;
            }
        }
        return close;
    }
};