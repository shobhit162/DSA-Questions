class Solution {
public:
    int find(vector<int>& nums){
        int a=0;
        int b=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=max(b+nums[i],a);
            b=a;
            a=sum;
        }
        return sum;
    }
    int rob(vector<int>& nums) {
         if(nums.size()==1)return nums[0];
        vector<int>dp(nums.begin(),nums.end()-1);
        vector<int>dp2(nums.begin()+1,nums.end());
       return max(find(dp),find(dp2));
    }
};