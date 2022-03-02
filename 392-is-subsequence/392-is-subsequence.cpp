class Solution {
public:
    bool isSubsequence(string s, string t) {
        int a=0;
        for(int i=0;i<t.size();i++){
            if(s[a]==t[i])
                a++;
        }
        if(a==s.size()) return true;
        else return false;
    }
};