class Solution {
public:
    int maxProduct(vector<int>& nums) {
          int n = nums.size(), res = nums[0], l = 1, r = 1;
        for (int i = 0; i < n; i++) {
            l =  (l) * nums[i];
            r =  (r) * nums[n - 1 - i];
            res = max(res, max(l, r));
            if(l==0)l=1;
            if(r==0)r=1;
        }
        return res;
        
//          int curr_product = 1, res = INT_MIN;
       
//        for (auto i: nums) {
//            curr_product = curr_product * i;
//            res = max(curr_product, res);
//            if(curr_product == 0) {
//                curr_product = 1;
//            }
//        }
       
//        curr_product = 1;
       
//        for (int i = nums.size()-1; i>=0; i--) {
//            curr_product = curr_product * nums[i];
//            res = max(curr_product, res);
//            if(curr_product == 0) {
//                curr_product = 1;
//            }      
//        }
//        return res;
    }
};