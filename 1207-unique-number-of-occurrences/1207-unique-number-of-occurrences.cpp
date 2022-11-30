class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        vector<int>vt;
        set<int>st;
        for(auto i=mp.begin();i!=mp.end();i++){
            vt.push_back(i->second);
            st.insert(i->second);
        }
        return vt.size()==st.size();
    }
};