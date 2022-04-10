class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>ans;
        int a=0;
        for(int i=0;i<ops.size();i++){
            if(ops[i]!="C" && ops[i]!="D" && ops[i]!="+")ans.push_back(stoi(ops[i]));
            else{
                if(ops[i]=="C")ans.pop_back();
                else if(ops[i]=="D"){
                    int q=ans[ans.size()-1];
                    ans.push_back(2*q);
                }
                else{
                    int q=ans[ans.size()-1];
                    int m=ans[ans.size()-2];
                    ans.push_back(q+m);
                }
            }
        }
        a=accumulate(ans.begin(),ans.end(),0);
        return a;
    }
};