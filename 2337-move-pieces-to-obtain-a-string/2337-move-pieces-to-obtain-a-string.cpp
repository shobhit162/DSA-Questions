class Solution {
public:
    bool canChange(string st, string tar) {
          int n=tar.length(),m=st.length();
        if(n!=m) return false;
    
        int a=0,b=0,i=0,j=0;
        while(i<n && j<n){
            
            while(i<n && tar[i]=='_') i++;
            while(j<n && st[j]=='_') j++;
            
            if(i==n || j==n){
                return i==n && j==n;
            }
            
            if(tar[i]!=st[j]) return false;
            
            if(tar[i]=='L'){
                if(j<i) return false;
            }
            else{
                if(i<j) return false;
            }
            
            i++;
            j++;
        }
        while(i<n && tar[i]=='_') i++;
        while(j<n && st[j]=='_') j++;
        return i==n && j==n;
//         int i=0;
//         int j=s.size()-1;
//         string ans;
//         for(int i=0;i<t.size();i++){
//             if(t[i]=='_' && s[i]=='_')ans.push_back('_');
//             else if(t[i]=='L' && s[i]=='L')ans.push_back('L');
//             else{
//                 while()
//             }
//         }
        
//         // while(i<=j){
//         //     if((s[i]=='_' || s[i]=='L') && (t[i]=='_' || t[i]=='L'))i++;
//         //     if((s[j]=='_' || s[j]=='R') && (t[j]=='_' || t[j]=='R'))j--;
//         //     else return false;
//         // }
//         // return true;
    }
};