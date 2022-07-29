class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>>ans;
        if(intervals.size()==0){
            return ans;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> tempint=intervals[0];
        for(auto it:intervals){
            if(it[0]<=tempint[1]){
                tempint[1]=max(it[1],tempint[1]);
            }
            else{
                ans.push_back(tempint);
                tempint=it;
            }
        }
        ans.push_back(tempint);
        return ans;
    }
};