class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int i=0; int ans=0;
        while(i<nums.size()-1) {
            if(nums[i] == nums[i+1]) {
                i++;
                ans++;
            } else {
                i+=2;
            }
        }
        if(i == nums.size()-1) return ans+1;
        return ans;
        
        
//         int count=0;
//         int i=0;
        
//             while(i<nums.size()){
//             if(i<nums.size()-1 && nums[i]==nums[i+1]){
//                 // int a=nums[i+1];
//                 count++;
//                 nums.erase(nums.begin()+i);
//                 // if(nums.size()<i)break;
//                 // cout<<nums.size()<<" ";
//                 i=0;
                
//             }
//             else i+=2;
//         }
//         if(nums.size()%2!=0)
//         return count+1;
//         else 
//             return count;
    }
};