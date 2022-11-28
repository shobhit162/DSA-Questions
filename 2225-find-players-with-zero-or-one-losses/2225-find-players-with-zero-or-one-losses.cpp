class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        vector<int> l0,l1;
        int n=mat.size();
        map<int,pair<int,int>> map;//player win loss
        for(auto it:mat){
            int winner=it[0],loser=it[1];
            map[winner].first++;
            map[loser].second++;
        }
        for(auto it:map){
            auto [win,loss]=it.second;
            int player=it.first;
            if(loss==0)l0.push_back(player);
            else if(loss==1)l1.push_back(player);
        }
        // we can use map in place of unordered_map for sorted order
        // sort(l0.begin(),l0.end());
        // sort(l1.begin(),l1.end());
        return {l0,l1};
    }
};