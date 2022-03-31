class Solution {
public:
    int isPossible(vector<int>&nums,int mid){
        int count=0;
        int tempsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(tempsum+nums[i]<=mid) tempsum+=nums[i];
            else {
                count++;
                tempsum=nums[i];
            }
        }
        count++; // kyuki initially hmne 0 liya toh ek to vaise bhi hoga hi na
        return count;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0;
        int r=0;
        for(int i=0;i<nums.size();i++){
            l=max(l,nums[i]);
            r+=nums[i];
        }
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            int count=isPossible(nums,mid);
            if(count<=m) r=mid-1, ans=mid;
            else l=mid+1;
        }
        return ans;
    }
};