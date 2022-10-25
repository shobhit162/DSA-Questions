class Solution {
public:
    // bool haveConflict(vector<string>& event1, vector<string>& event2) {
    //     string s1=event1[0];
    //     string s2=event1[1];
    //     string s3=event2[0];
    //     string s4=event2[1];
    //     string ss1="";
    //     ss1+=s1.substr(0,2);
    //     ss1+=s1.substr(3,4);
    //     string ss2="";
    //     ss2+=s2.substr(0,2);
    //     ss2+=s2.substr(3,4);
    //     string ss3="";
    //     ss3+=s3.substr(0,2);
    //     ss3+=s3.substr(3,4);
    //     string ss4="";
    //     ss4+=s4.substr(0,2);
    //     ss4+=s4.substr(3,4);
    //     int x=stoi(ss1);
    //     int y=stoi(ss2);
    //     int a=stoi(ss3);
    //     int b=stoi(ss4);
    //     if((a>=x && a<=y) || (b>=x && b<=y) || (x>=a && x<=b) || (y>=a && y<=b))return true;
    //     // cout<<x<<" "<<y<<" "<<a<<" "<<b<<" ";
    //     return false;
    // }
    //   bool haveConflict(vector<string>& e1, vector<string>& e2) {
    //     return e1[0] <= e2[1] && e2[0] <= e1[1];
    // }
        bool haveConflict(vector<string>& e1, vector<string>& e2) {
        return max(e1[0], e2[0]) <= min(e1[1], e2[1]);
    }
};