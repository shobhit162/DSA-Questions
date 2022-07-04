class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
          vector<int> j(2001,0);
    int mod=pow(10,9)+7;
    
    j[1]=1;
    
    for(int i=1;i<=n;i++){
        for(int k=i+delay;k<i+forget;k++){
            j[k]=(j[k]+j[i])%mod;   
        }
    }
    
    int i=0;
    long long int ans=0;
    
    while(forget--){
        ans=(ans+j[n-i])%mod;
        i++;
    }
    return ans;
    }
};