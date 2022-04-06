class Solution {
public:
    // int searchidx(vector<int>& vt,int x){
    //     int s=0,e=vt.size()-1,mid;
    //     while(s<=e){
    //         mid=(s+e)/2;
    //         if(vt[mid]==x)return mid;
    //         else if(vt[mid]>x)e=mid-1;
    //         else s=mid+1;
    //     }
    //     return -1;
    // }
    int threeSumMulti(vector<int>& arr, int X) {
          int n = arr.size(), mod = 1e9+7, ans = 0;
        unordered_map<int, int> m;
        
        for(int i=0; i<n; i++) {
            ans = (ans + m[X - arr[i]]) % mod;
            
            for(int j=0; j<i; j++) m[arr[i] + arr[j]]++;
        }
        return ans;
//         long long count=0,n=vt.size(),mod=1000000007;
        
//         for(int i=0;i<n-2;i++){
//             for(int j=i+1;j<n-1;j++){
//                 int sum=vt[i]+vt[j];
//                 for(int z=j+1;z<n;z++)if(sum+vt[z]==target)count++;
//             }
//         }
        
        // sort(vt.begin(),vt.end());
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 int twosum=vt[i]+vt[j];
//                 if(i!=j && binary_search(vt.begin(),vt.end(),target-twosum)){
//                     int k=searchidx(vt,target-twosum);
//                     cout<<k<<" ";
//                     if(k>j && k>i){
//                         count=count%mod;
//                         count++;
//                     }
//                     // if(vt[k]==vt[k+1])count++;
        
//                 }
//             }
//         }
        // return count%mod;
    }
};