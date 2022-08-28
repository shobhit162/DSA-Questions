class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
         int n = mat.size(), m = mat[0].size();
        // observation:
        // for each cell mat[i][j] in the same diagonal,
        // they will have the same value i - j
        
        // if the diagonal line is pointing to upper right direction, 
        // then they will have the same value i + j (see https://leetcode.com/problems/diagonal-traverse/)
        
        // the idea is to use priority queue for each diagonal
        // as priority queue could sort it internally when a value is pushed / popped
        // we use greater<int> as we want the smallest go first
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> diag;
        // iterate each row
        for (int i = 0; i < n; i++) {
            // iterate each col
            for (int j = 0; j < m; j++) {
                // for each mat[i][j] 
                // add it to corresponding priority queue
                diag[i - j].push(mat[i][j]);
            }
        }
        // iterate each row
        for (int i = 0; i < n; i++) {
            // iterate each col
            for (int j = 0; j < m; j++) {
                // diag[i - j].top() would return the smallest number in the current queue
                // we can just perform in-place replacement here
                mat[i][j] = diag[i - j].top();
                // since we don't need this value anymore, pop it out
                // so that next cell would get the smallest value
                diag[i - j].pop();
            }
        }
        return mat;
    }
};