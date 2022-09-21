class Solution {
public:
          // the idea is we don't calculate the even sum from scratch for each query
    // instead, we calculate it at the beginning
    // since each query only update one value, 
    // so we can base on the original value and new value to adjust the even sum
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        // calculate the sum of all even numbers
        for (auto x : nums) {
            if (x % 2 == 0) {
                evenSum += x;
            }
        }
        vector<int> ans;
        for (auto q : queries) {
            int val = q[0], idx = q[1];
            // if original nums[idx] is even, then we deduct it from evenSum
            if (nums[idx] % 2 == 0) evenSum -= nums[idx];
            // in-place update nums
            nums[idx] += val;
            // check if we need to update evenSum for the new value
            if (nums[idx] % 2 == 0) evenSum += nums[idx];
            // then we have evenSum after this query, push it to ans 
            ans.push_back(evenSum);
        }
        return ans;
    }
};