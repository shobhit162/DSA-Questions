class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
      int ans=0,prev=0,i=0,pd=-1;
        for(auto it:logs){
            int d=(it[1]-prev);
            if(pd==-1 || d>=pd){
                if(d==pd){
                    ans=min(it[0],ans);
                }
                else
                 ans=it[0];
            }
            pd=max(pd,d);
            prev=it[1];
        }
        return ans;
    }
};