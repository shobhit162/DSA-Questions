class Solution {
public:
    int maxArea(int h, int w, vector<int>& he, vector<int>& v) {
        sort(he.begin(),he.end());
         sort(v.begin(),v.end());
        int max1=he[0];
        int max2=v[0];
        if(he.size()==1){
            max1=max(he[0],h-he[0]);
        }
        else{
            for(int i=0;i<he.size()-1;i++){
                max1=max(he[i+1]-he[i],max1);
            }
            max1=max(max1,h-he.back());
        }
         if(v.size()==1){
            max2=max(v[0],w-v[0]);
        }
         else{
            for(int i=0;i<v.size()-1;i++){
                max2=max(v[i+1]-v[i],max2);
            }
             max2=max(max2,w-v.back());
        }
        cout<<max1<<" "<<max2;
        long long m1=max1;
        long long m2=max2;
        long long ans=(m1*m2)%1000000007;
        return ans;
        
    }
};