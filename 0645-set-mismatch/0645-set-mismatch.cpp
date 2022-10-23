class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        int tot=0;
        int tot1=0;
       unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            tot+=(i+1);
            if(mp.find(nums[i])!=mp.end()){
                ans.push_back(nums[i]);
               
            }
            else{
            mp[nums[i]]++;
               tot1+=nums[i]; 
            }
        }
        int y=abs(tot1-tot);
        ans.push_back(y);
        return ans;
    }
};