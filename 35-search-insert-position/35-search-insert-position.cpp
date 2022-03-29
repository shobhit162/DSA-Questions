class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
         int n=nums.size();
        int left=0,right=n;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=target) right=mid;
            else left=mid+1;
        }
        return left;
        
        // binary search lgani h
       //  bool flag=0;
       //  int index=0;
       //  for(int i=0;i<nums.size();i++){
       //      if(nums[i]==target){
       //          index= i;
       //          flag=1;
       //          break;
       //      }
       //      else if(nums[i]>target) {
       //          index= i;
       //          flag=1;
       //          break;
       //      }
       //  }
       // if(!flag) return nums.size();
       //  else
       //  return index;
    }
};