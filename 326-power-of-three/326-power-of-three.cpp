class Solution {
public:
    bool isPowerOfThree(int n) {
        // if(n==1)return true;
        // while(n>3){
        //     n=n/3;
        //     if(n==3)break;
        // }
        // if(n==3)return true;
        // else return false;
        
         if(n==0) return false;                // if 0 return false
        while(n%3==0) n /= 3;                 // check till ,it is divisible by 3 as we need to check power 3 
        return n==1;                          // if it remains as 1 then return true else false
    }
};