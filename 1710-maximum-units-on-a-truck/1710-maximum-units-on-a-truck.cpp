class Solution {
public:
  static bool sorttype(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] > v2[1];
}
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),sorttype);
        int ans=0;
        int count=0;
        for(auto i:boxTypes)cout<<i[0]<<" "<<i[1]<<endl;
        for(int i=0;i<boxTypes.size();i++){
            if(count>=truckSize)break;
            while(boxTypes[i][0]!=0 && count!=truckSize){
                count++;
                ans+=boxTypes[i][1];
                boxTypes[i][0]--;
            }
            
        }
        return ans;
    }
};