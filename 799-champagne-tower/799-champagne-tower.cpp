class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double arr[101][101]={0};
        arr[0][0]=poured;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                if(arr[i][j]>=1){
                    arr[i+1][j]+=(arr[i][j]-1)/2.0;
                    arr[i+1][j+1]+=(arr[i][j]-1)/2.0;
                    arr[i][j]=1;
                }
            }
        }
        return arr[query_row][query_glass];
    }
};