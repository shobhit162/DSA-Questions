class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        //  int n=grid.size();
        // int m=grid[0].size();
        // int total=n*m;
        // vector<int>element;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++)element.push_back(grid[i][j]);
        // }
        // vector<vector<int>>ans;
        // vector<int>temp;
        // int i=0;
        // k=k%total;
        // i=total-k;
        // // cout<<i<<" ";
        // for(;i<total;i++){
        //     temp.push_back(element[i]);
        //     if(temp.size()==m){
        //         ans.push_back(temp);
        //         temp.clear();
        //     }
        // }
        // for(i=0;i<total-k;i++){
        //     temp.push_back(element[i]);
        //     if(temp.size()==m){
        //         ans.push_back(temp);
        //         temp.clear();
        //     }
        // }
        // return ans;
    //     ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
          int row=grid.size(),column=grid[0].size();
        int total=row*column;
        vector<vector<int>> ans;
        vector<int> vt(total,1);
        vector<int> temp;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                temp.push_back(grid[i][j]);
            }
        }
        // cout<<temp.size()<<endl;
        for(int i=0;i<temp.size();i++){
            if(i+k>=temp.size()){
                vt[(i+k)%temp.size()]=temp[i];
            }
            else{
                vt[i+k]=temp[i];
            }
        }
        // for(auto i:vt)cout<<i<<" ";
        // int x=0,cc=0;
        vector<int>temp1;
        cout<<ans.size()<<" ";
        for(int i=0;i<vt.size();i++){
            temp1.push_back(vt[i]);
            if(temp1.size()==column){
                ans.push_back(temp1);
                temp1.clear();
            }
            
            // if(i-cc+1>row){
            //     x++;cc+=row;
            // }
            // else if(i!=0 && column==1){
            //     x++;cc+=1;
            // }
            // ans[x][i-cc]=vt[i];
        }
        return ans;
    }
};