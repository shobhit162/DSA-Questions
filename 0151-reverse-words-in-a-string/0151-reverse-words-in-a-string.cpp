class Solution {
public:
    string reverseWords(string s) {
         stringstream ss(s);
        string tmp, ans;
        while (ss >> tmp) {
            ans = ' ' + tmp + ans;
        }
        ans.erase(0, 1);
        return ans;
    }
};