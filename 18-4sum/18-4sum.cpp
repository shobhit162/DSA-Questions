class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {   // O(n*n*n)
        vector<vector<int>>res;
        if(!nums.size())
            return res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                // int tar=target-nums[j]-nums[i];
                long long int tar = 1LL*target - 1LL*nums[ i ]  -  1LL*nums[ j ];
                int front=j+1;
                int back=nums.size()-1;
                while(front<back){
                    if(tar>nums[front]+nums[back])
                        front++;
                    else if(tar<nums[front]+nums[back])
                        back--;
                    else{
                        vector<int>temp(4,0);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[front];
                        temp[3]=nums[back];
                        res.push_back(temp);
                        while(front<back && nums[front]==temp[2]) front++;
                        while(front<back && nums[back]==temp[3]) back--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
             while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};