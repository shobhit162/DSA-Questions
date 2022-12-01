class Solution {
public:
    bool halvesAreAlike(string s) {
    //     int cnt=0;
    //     for(int i=0;i<s.size();i++){
    //         s[i]=tolower(s[i]);
    //         if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)cnt++;
    //     }
    //     if(cnt%2==0)return true;
    //     else return false;
    // }
    int t=0;
        for(int i=0;i<s.size();i++)
        {   
            s[i]=tolower(s[i]);
            if(i<s.size()/2)
            {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                      t++;                  // counting for the first half of the string
            }
            else
            {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                     t--;            // reducing the count if occures in second half of the string 
            }     
        } 
       return (t==0);
    }
};