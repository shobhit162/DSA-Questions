class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        long long mod=1e9+7;
        for(auto num:nums)pq.push(num);
        while(k--){
            int top=pq.top();
            pq.pop();
            top=top+1;
            pq.push(top);
        }
        long long ans=1;
        while(pq.size()>0){
            long long top=pq.top();
            pq.pop();
            ans=(ans*top)%mod;
        }
        return ans;
        
        // sort(nums.begin(),nums.end());
        // long long ans=1;
        // for(int i=0;i<nums.size()-1;i++){
        //     while(nums[i]<=nums[i+1] && k>0){
        //         // cout<<nums[i]<<" ";
        //         nums[i]++;
        //         k--;
        //     }
        //     if(k>0 && i==nums.size()-2){
        //         sort(nums.begin(),nums.end());
        //         // for(auto i:nums)cout<<i<<" ";
        //         i=-1;
        //     }
        // }
        // for(int i=0;i<nums.size();i++)ans*=nums[i];
        // return ans%1000000007;
    }
};