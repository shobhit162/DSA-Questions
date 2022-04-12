class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                int count=countlive(board,i,j);
                if(board[i][j] && count<2)
                    board[i][j]=-1;
                if(board[i][j] && count>3)
                    board[i][j]=-1;
                if(board[i][j]==0 && count==3)
                    board[i][j]=2;
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==-1)  
                    board[i][j]=0;
                else if(board[i][j]==2) 
                    board[i][j]=1;
            }
        }
    }
    int countlive(vector<vector<int>>& board, int i, int j){
        int count=0;
        int a=board.size();
        int c=board[0].size();
        if(i-1>=0 && j-1>=0 && i-1<a && j-1<c){
            if(board[i-1][j-1]==-1 || board[i-1][j-1]==1)
                count++;
        }
        if(i-1>=0 && j>=0 && i-1<a && j<c){
            if(board[i-1][j]==-1 || board[i-1][j]==1)
                count++;
        }
        if(i-1>=0 && j+1>=0 && i-1<a && j+1<c){
            if(board[i-1][j+1]==-1 || board[i-1][j+1]==1)
                count++;
        }
        if(i>=0 && j-1>=0 && i<a && j-1<c){
            if(board[i][j-1]==-1 || board[i][j-1]==1)
                count++;
        }
        if(i+1>=0 && j>=0 && i+1<a && j<c){
            if(board[i+1][j]==-1 || board[i+1][j]==1)
                count++;
        }
        if(i+1>=0 && j+1>=0 && i+1<a && j+1<c){
            if(board[i+1][j+1]==-1 || board[i+1][j+1]==1)
                count++;
        }
        if(i+1>=0 && j-1>=0 && i+1<a && j-1<c){
            if(board[i+1][j-1]==-1 || board[i+1][j-1]==1)
                count++;
        }
        if(i>=0 && j+1>=0 && i<a && j+1<c){
            if(board[i][j+1]==-1 || board[i][j+1]==1)
                count++;
        }
        return count;
    }
                  
};



// class Solution {
// public:
//     void gameOfLife(vector<vector<int>>& board) {
//            int row=board.size();
//         int column=board[0].size();
//         int n=row,m=column;
//         vector<int> vt;
//         vector<vector<int>> ans;
//         int one=0;
//         for(int i=0;i<row;i++){
//             for(int j=0;j<column;j++){
//                 if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1){
//                     one++;
//                 }
//                 if(i+1<n && j+1<m && board[i+1][j+1]==1){
//                     one++;
//                 }
//                 if(j-1>=0 && board[i][j-1]==1){
//                     one++;
//                 }
//                 if(i-1>=0 && board[i-1][j]==1){
//                     one++;
//                 }
//                 if(i+1<n && board[i+1][j]==1){
//                     // one++;
//                 }
//                 if(j+1<m && board[i][j+1]==1){
//                     one++;
//                 }
//                 if(i-1>=0 && j+1<m && board[i-1][j+1]==1){
//                     one++;
//                 }
//                 if(i+1<n && j-1>=0 && board[i+1][j-1]==1){
//                     one++;
//                 }
//                 if(board[i][j]==1){
//                     if(one<2 || one>3){
//                         vt.push_back(0);
//                     }
//                     else vt.push_back(1);
//                 }
//                 else if(board[i][j]==0){
//                     if(one==3){
//                         vt.push_back(1);
//                     }
//                     else vt.push_back(0);
//                 }
//                 one=0;
//             }
//         }
//         vector<int> temp;
//         for(int i=0;i<vt.size();i++){
//             temp.push_back(vt[i]);
//             if(temp.size()==column){
//                 ans.push_back(temp);
//                 temp.clear();
//             }
//         }
//         //output
//         for(int i=0;i<ans.size();i++){
//             for(int j=0;j<ans[i].size();j++){
//                 board[i][j]=ans[i][j];
//             }
           
//         }
//     }
// };