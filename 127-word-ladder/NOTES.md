​
unordered_set<string>myset;
bool isPresent=false; //check if endword is present in dictionary
//Insert all word from dict in myset
for(auto word:wordList){
if(endWord.compare(word)==0)
isPresent=true;
myset.insert(word);
}
if(isPresent==false) //endword is not present in dict
return 0;
queue<string>q;
q.push(beginWord);
int depth=0;
while(!q.empty()){
depth+=1;
int lsize=q.size(); // No of element at a level
while(lsize--){
string curr=q.front();
q.pop();
//check for all possible 1 depth word
for(int i=0;i<curr.length();i++){   //fpr each index
string temp=curr;