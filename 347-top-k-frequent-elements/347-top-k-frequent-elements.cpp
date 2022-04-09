class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
        vector<int>ans;
           for(int i=0;i<nums.size();i++)mp[nums[i]]++;
      priority_queue<pair<int,int>>pq;
        for(auto i=mp.begin();i!=mp.end();i++){
            pq.push({i->second,i->first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

//     unordered_map<int, int> counts;
//         for(auto i : nums) ++counts[i];
        
//         vector<vector<int>> buckets(nums.size() + 1);
//         for(auto & k : counts) 
//             buckets[k.second].push_back(k.first);
//         reverse(begin(buckets), end(buckets));
        
//         vector<int> res;
//         for(auto & bucket: buckets) 
//             for(auto i : bucket) {
//                 res.push_back(i);
//                 if(res.size() == k) return res;
//             }
        
//         return res;