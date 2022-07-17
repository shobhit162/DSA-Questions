class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<long long int, vector<long long int>>mp;
        long long ans=-1;
        for(int i=0;i<nums.size();i++){
            int temp=0;
            int x=nums[i];
            while(x>0){
                int m=x%10;
                temp+=m;
                x=x/10;
            }
            mp[temp].push_back(nums[i]);
        }
        for(auto it:mp){
			int n = it.second.size();
			if(n>1){
				sort(it.second.begin(), it.second.end());
				ans=max(ans,(it.second[n-2]+it.second[n-1]));
			}
		}
        return ans;
    }
};



// 		long long int maxSum = -1;

// 		for(auto it:mp){
// 			int n = it.second.size();
// 			if(n>1){
// 				sort(it.second.begin(), it.second.end());
// 				maxSum = max(maxSum, (it.second[n-2]+it.second[n-1]));
// 			}
// 		}

// 		return maxSum;
// 	}