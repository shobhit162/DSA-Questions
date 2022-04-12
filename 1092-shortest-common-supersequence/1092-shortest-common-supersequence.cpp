class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
//           int n=s1.size(); 
//         int m=s2.size();
//         int t[n+1][m+1]; //table generated while computing LCS length
//         string res; // result	
//         // compute LCS length using tabulation      
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++)
//         {
//             if(i==0||j==0)
//                 t[i][j]=0;
//             else if(s1[i-1]==s2[j-1])
//             {
//                 t[i][j]=1+t[i-1][j-1];
//             }
//             else
//             {
//                 t[i][j]=max(t[i-1][j],t[i][j-1]);
//             }
//         }
//     }     
//        //print lcs
//     int i=n,j=m;
//     while(i>0 && j>0)
//     {
//         if(s1[i-1]==s2[j-1])
//         {
//             res.push_back(s1[i-1]);
//             i--;
//             j--;
//         }
//         else
//         {
//             if(t[i-1][j]>t[i][j-1])
//             {
//                 res.push_back(s1[i-1]);
//                 i--;
//             } else{
//                 res.push_back(s2[j-1]);
//                 j--;
//             }
//         }
//     }
//     while(i>0) // if s1 characters are still left
//     {
//         res.push_back(s1[i-1]);
//         i--;
//     }
//     while(j>0) //if s2 characters are still left
//     {
//         res.push_back(s2[j-1]);
//         j--;
        
//     }
//         reverse(res.begin(),res.end()); 
//         return res;
        
        // bottom up dp
        //
        int n=str1.size();
        int m=str2.size();
        int dp[n+1][m+1];
        // for(int i=0;i<n+1;i++)dp[i][0]=0;
        // for(int j=0;j<m+1;j++)dp[0][j]=0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
          if(i==0||j==0)
               dp[i][j]=0;
               else if(str1[i-1]==str2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=n;
        int j=m;
        string s="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s.push_back(str1[i-1]);
                i--;
                j--;
            }
             else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                s.push_back(str1[i-1]);
                i--;
            } else{
                s.push_back(str2[j-1]);
                j--;
            }
        }
            // else if(dp[i][j-1]>dp[i-1][j]){
            //     s.push_back(str2[j-1]);
            //     j--;
            // }
            // else if(dp[i-1][j]>dp[i][j-1]){
            //     s.push_back(str1[i-1]);
            //     i--;
            // }
        }
        while(i>0){
            s.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            s.push_back(str2[j-1]);
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};