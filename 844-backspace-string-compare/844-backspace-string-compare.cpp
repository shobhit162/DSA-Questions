class Solution {
public:
    bool backspaceCompare(string s, string t) {
       string r="";
        string g="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='#')r.push_back(s[i]);
            if(s[i]=='#'){
                if(r.size()>0)
                r.pop_back();
            }
        }
         for(int i=0;i<t.size();i++){
            if(t[i]!='#')g.push_back(t[i]);
            if(t[i]=='#')
            {
                if(g.size()>0)
                g.pop_back();
            }
         }
        return r==g;
        }
};