class Solution {
public:
    // string breakPalindrome(string p) {
    //     string ans="";
    //     if(p.size()==1)return ans;
    //     int mid=p.size();
    //     if(mid%2!=0){
    //         mid/=2;
    //         mid+=1;
    //     }
    //     for(int i=0;i<p.size();i++){
    //         if(p.size()%2!=0 &&i==mid-1)continue;
    //         if(p[i]!='a'){
    //             ans+=p.substr(0,i);
    //            ans+="a";
    //             ans+=p.substr(i+1);
    //             break;
    //         }
    //          if(i==p.size()-1 && p[i]=='a'){
    //             ans+=p.substr(0,i);
    //             ans+="b";
    //         }
    //     }
    //     return ans;
    // }
     string breakPalindrome(string S) {
        int n = S.size();
        for (int i = 0; i < n / 2; ++i) {
            if (S[i] != 'a') {
                S[i] = 'a';
                return S;
            }
        }
        S[n - 1] = 'b';
        return n < 2 ? "" : S;
    }
};