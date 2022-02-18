class Solution {
public:
    string removeKdigits(string num, int k) {
         int n=num.size();
        stack<char>mystack;
        for(char c:num){  //store the final string in stack
            while(!mystack.empty() && k>0 && mystack.top()>c){
                mystack.pop();
                k--;
            }
            if(!mystack.empty() || c!='0')
                mystack.push(c);
        }
            while(!mystack.empty() && k--)  //removing the largest value from top
                mystack.pop();
            if(mystack.empty())
                return "0";
              //now retrieve the number from stack into string
            while(!mystack.empty()){
                num[n-1]=mystack.top();
                mystack.pop();
                n--;
            }
        return num.substr(n);
    }
};