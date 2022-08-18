class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> nums;
        int count=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]){
                count++;
            }
            else{
                nums.push_back(count);
                count=1;
            }
        }
        nums.push_back(count);//here our last elements count will be pushed
        sort(nums.begin(),nums.end(),greater<int>());
        count=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            count+=nums[i];
            ans++;
            if(2*count>=arr.size()){
                break;
            }
        }
        return ans;
    }
};