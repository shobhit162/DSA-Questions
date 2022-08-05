class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
	// unordered_set<int> s(begin(nums), end(nums));
	// int longest = 0;
	// for(auto& num : s) {
	// if(s.count(num - 1)) continue;
	// 	int j = 1;
	// 	while(s.count(num + j)) j++;
	// 	longest = max(longest, j);
	// }
	// return longest;
        if(nums.size()==0) return 0;
        int maxi=0;
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]) continue;
            if(nums[i]==nums[i+1]-1){
                count++;
                maxi=max(maxi,count);
            }
            else count=0;
        }
        return maxi+1;
    }
};