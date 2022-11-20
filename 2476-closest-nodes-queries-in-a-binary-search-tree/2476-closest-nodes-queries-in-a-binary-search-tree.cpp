/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//     vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
//         vector<vector<int>>ans;
//         for(int i=0;i<queries.size();i++){
//             vector<int>temp;
//         if(root->val==queries[i]){
//             temp.push_back(root->val);
//             temp.push_back(root->val);
//         }
//             else if(root->val>queries[i]){
                
//             }
//         }
//     }
//     int find(TreeNode* root, int tar){
        
//     }
     void inorder(TreeNode* root, vector<int>& nums){
        if(root){
            inorder(root->left, nums);
            nums.push_back(root->val);
            inorder(root->right, nums);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> nums;
        inorder(root, nums);
        
        for(auto q: queries){
            int mn = -1, mx = -1;
            if( nums[0] <= q ) mn = (lower_bound(nums.begin(), nums.end(), q)) - nums.begin();
            if( q <= nums.back() ) mx = (upper_bound(nums.begin(), nums.end(), q))-nums.begin();
            
            if(mn > 0 && mn >= nums.size()) mn--;   //when q is larger than nums.back()
            if(mn >= 0 && nums[mn] > q) mn--;         //when q is not present in the nums array
            if(mx > 0 && nums[mx - 1] == q) mx--;    //when q is present in nums, upper bound refer to next element
            
            if(mn != -1) mn = nums[mn];      //get value at index mn
            if(mx != -1) mx = nums[mx];      //get value at index mx
            ans.push_back({mn, mx});
        }
        return ans;
    }
};