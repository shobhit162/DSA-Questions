// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
            int v = 0;
    int i = B.size() - 1;
    if(A.size() != B.size()) return -1;
    //Traverse from back for both the strings if 
    //not equal will move to front so count the op
    //else decrement counter
    for(int j = A.size()-1; j >= 0; j--){
         if(A[j] != B[i])
             v++;
          else
            i--;
    }
    //if both string not equal then return -1 else count of op
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if(A != B) return -1;
    return v;

    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends