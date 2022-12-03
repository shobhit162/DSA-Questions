class Solution {
public:
    string frequencySort(string s) {
        // unordered_map<char,int> freq;           //for frequency of characters
        // priority_queue<pair<int,char>> maxheap; //maxheap according to frequency of characters
        // for(char c: s)
        //     freq[c]++;
        // for(auto it: freq)
        //     maxheap.push({it.second,it.first}); //heap will be constructed on the basis of frequency
        // s="";   
        // while(!maxheap.empty()){
        //     s+=string(maxheap.top().first,maxheap.top().second); //frequency times the character
        //     maxheap.pop();
        // }
        // return s;
        
        // using lambda, comparator function
        
         int counts[256] = {0};
        for (char ch : s)
            ++counts[ch];
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
        });
        return s;
    }
};