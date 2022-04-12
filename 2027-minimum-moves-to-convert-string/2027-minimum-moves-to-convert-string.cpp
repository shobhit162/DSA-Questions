class Solution {
public:
    int minimumMoves(string s) {
        int move=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='X'){
                move++;
                i+=2;
            }
        }
        return move;
    }
};