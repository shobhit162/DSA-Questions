class Solution {
public:
    bool check(string s,int i,int j){
        bool dekho=true;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                dekho=false;
                break;
            }
        }
        return dekho;
    }
    bool validPalindrome(string s) {
        bool flag=true;
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
              bool a=check(s,i+1,j);
                bool b=check(s,i,j-1);
                if(a || b){break;}
                flag=(a || b);
                if(!flag)break;
            }
        }
        return flag;
        // unordered_map<char,int>mp;
        // for(int i=0;i<s.size();i++){
        //     mp[s[i]]++;
        // }
        // int count=0;
        // for(char a=;i<mp.size();i++){
        //     if(mp[i]==1 && i!=s.size()/2)count++;
        // }
        // if(count<=1)return true;
        // else return false;
    }
};