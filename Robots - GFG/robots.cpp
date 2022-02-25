// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string moveRobots(string s1, string s2){
        // code here 
         if (s1.length() != s2.length()) return "No";
        int a1 = 0, b2 = 0;
        for(int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == 'A') a1++;
            if (s2[i] == 'A') a1--; 
            if (s1[i] == 'B') b2--;
            if (s2[i] == 'B') b2++;
            if (a1 > 0 || b2 > 0 || (b2 < 0 && a1 < 0)) return "No";
        }
        return "Yes";
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends