class Solution {
public:
    void reverseString(vector<char>& s) {
        int so=0;
        int l=s.size()-1;
        while(so<l){
            swap(s[so],s[l]);
            so++;
            l--;
        }
    }
    
};