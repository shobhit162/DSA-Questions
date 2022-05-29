class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int>mp;
        for(auto r:s){
            mp[r]++;
        }
        int ans=0;
    
        while(true){
            int count=0;
            for(int i=0;i<target.size();i++){
                if(mp[target[i]]){
                    mp[target[i]]--;
                }
                else return ans;
            }
            ans++;
        }
        return ans;
      // int n=target.size();
      //   int y=0;
      //   int ans=0;
      //   int r=0;
      //   for(int i=0;i<s.size();i++){
      //       for(r=0;r<target.size();r++){
      //           if(s[i]==s[r]){
      //               y++;
      //               r++;
      //               cout<<y<<" ";
      //               i++;} 
      //           if(y==n){
      //               ans++;
      //               y=0;
      //           }
      //       }
      //   }
      //   return ans;
    }
};