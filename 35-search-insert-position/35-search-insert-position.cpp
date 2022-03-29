class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // binary search lgani h
        bool flag=0;
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                index= i;
                flag=1;
                break;
            }
            else if(nums[i]>target) {
                index= i;
                flag=1;
                break;
            }
        }
       if(!flag) return nums.size();
        else
        return index;
    }
};