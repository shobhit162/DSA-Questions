class Solution {
public:
    int tribonacci(int n) {
        int F[38];
        F[0]=0;
        F[1]=F[2]=1;
        for(int i=0;i<n-2;i++)
            F[i+3]=F[i]+F[i+1]+F[i+2];
        return F[n];
    }
};