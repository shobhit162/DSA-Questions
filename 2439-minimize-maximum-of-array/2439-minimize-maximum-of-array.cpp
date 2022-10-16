class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
//         int prev=0;
//         int maxi=0;
//         int curr=0;
//         for(int i=0;i<1000000;i++){
//             int j=max_element(nums.begin()+1,nums.end())-nums.begin();
//             if(nums[j-1]>=nums[j])return nums[j-1];
//             nums[j]--;
//             nums[j-1]++;
            
//         }
//         return *max_element(nums.begin(),nums.end());
            long long minmax = 0, sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        minmax = max((sum + i) / (i + 1), minmax);  // sum+i hmara ceil ki tarah kaam krega
    }
    return minmax;
    }
};