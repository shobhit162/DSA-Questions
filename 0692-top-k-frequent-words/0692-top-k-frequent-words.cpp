class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        vector<int> v;
        vector<string> res;
        for(auto x:words)
        {
            m[x]++;
        }
        
        for(auto x:m)
            {
                v.push_back(x.second);

            }
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<k;i++)
        {   int temp=v[i];
            for(auto x:m)
            {
                if(x.second==temp)
                    {res.push_back(x.first);
                    m.erase(x.first);
                    break;
                    }
            }
            
          
        }
      return res;  
    }
};