class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int a=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                a++;
                if(i-2<0 || nums[i-2]<=nums[i])nums[i-1]=nums[i];
                else if(nums[i]<nums[i-2])nums[i]=nums[i-1];
            }
        }
        if(a<=1)return true;
        return false;
    }
};