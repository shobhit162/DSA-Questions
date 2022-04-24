class Solution {
public:
    void solve(set<pair<int,int>> &st, vector<int>vt){
        int x=vt[0],y=vt[1],r=vt[2];
        for(int i=x-r;i<=x+r;i++){
            for(int j=y-r;j<=y+r;j++){
                if(((x-i)*(x-i)+(y-j)*(y-j))<=(r*r))st.insert({i,j});
            }
        }
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>>st;
        for(int i=0;i<circles.size();i++){
            solve(st,circles[i]);
        }
        return st.size();
    }
};