class Solution {
public:
    int longestPalindrome(vector<string>& words) {
    //      unordered_map<string, int> m;
    // int unpaired = 0, ans = 0;
    // for (string w: words) {
    //     if (w[0] == w[1]) {
    //         if (m[w] > 0) {
    //             unpaired--;
    //             m[w]--;
    //             ans += 4;
    //         }
    //         else {
    //             m[w]++;
    //             unpaired++;
    //         }
    //     }
    //     else {
    //         string rev = w;
    //         reverse(rev.begin(), rev.end());
    //         if (m[rev] > 0) {
    //             ans += 4;
    //             m[rev]--;
    //         }
    //         else m[w]++;
    //     }
    // }
    // if (unpaired > 0) ans += 2;
    // return ans;
        unordered_map<string,int>mp;
        int same=0,ans=0;
        for(string i:words){
            if(i[0]==i[1]){
                if(mp[i]>0){
                    same--;
                    mp[i]--;
                    ans+=4;
                }
                else{
                    mp[i]++;
                    same++;
                }
            }
            else{
                string rev=i;
                reverse(rev.begin(),rev.end());
                if(mp[rev]>0){
                    ans+=4;
                    mp[rev]--;
                }
                else{
                    mp[i]++;
                }
            }
        }
        if(same>0)ans+=2;
        return ans;
    }
};

