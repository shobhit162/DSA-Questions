class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool flag=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                flag=1;
                break;
            }
        }
        return flag;
    }
};