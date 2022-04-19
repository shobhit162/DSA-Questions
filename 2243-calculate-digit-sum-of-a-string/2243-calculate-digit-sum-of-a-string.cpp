class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string ans="";
            int count=0;
             int num=0;
            for(int i=0;i<s.size();i++){
                num+=(s[i]-'0');
                count++;
                if(count==k){
                count=0;
                ans+=to_string(num);
                num=0;
                }
            }
           if(count>0){
               ans+=to_string(num);
           }
            s=ans;
           
        }
        return s;
    }
};

  // while ((int) s.size() > k) {
  //           int sum = 0;
  //           string t = "";
  //           int count = 0;
  //           for (int i = 0; i < (int) s.size(); i++) {
  //               sum += (s[i] - '0');
  //               ++count;
  //               if (count == k) {
  //                   t += to_string(sum);
  //                   sum = 0;
  //                   count = 0;
  //               }
  //           }
  //           if (count > 0) {
  //               t += to_string(sum);
  //           }
  //           s = t;
  //       }
  //       return s;