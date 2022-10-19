class Solution {
public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         map<string,int> m;
//         vector<int> v;
//         vector<string> res;
//         for(auto x:words)
//         {
//             m[x]++;
//         }
        
//         for(auto x:m)
//             {
//                 v.push_back(x.second);

//             }
//         sort(v.begin(),v.end(),greater<int>());
//         for(int i=0;i<k;i++)
//         {   int temp=v[i];
//             for(auto x:m)
//             {
//                 if(x.second==temp)
//                     {res.push_back(x.first);
//                     m.erase(x.first);
//                     break;
//                     }
//             }
            
          
//         }
//       return res;  
//     }
    
     static bool comparator(pair<string,int>& a, pair<string,int>& b){
        if(a.second != b.second){
            return a.second > b.second;
        }else{
            return a.first < b.first;
        }
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto x : words){
            m[x]++;
        }
        
        vector<pair<string,int>> newV;
        for(auto x : m){
            pair p{x.first, x.second};
            newV.push_back(p);
        }
        
        sort(newV.begin(),newV.end(),comparator);
        
        vector<string> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(newV[i].first);
        }
        
        return ans;
        
    }
};