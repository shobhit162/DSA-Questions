class Solution {
public:
     vector<int>* precursor;
	vector<vector<string>> res;
	bool isANeighbor(string& s1, string& s2) {
		bool hasChanged = false;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				if (hasChanged)
					return false;
				else
					hasChanged = true;
			}
		}
		return true;
	}
	void generateRoute(vector<string> right, vector<int>& precursor2, vector<string>& wordList) {
		if (precursor2.size() == 0) {
			res.push_back(right);
			return;
		}
		vector<string> copy;
		for (int i = 0; i < precursor2.size(); i++) {
			copy = right;
			// insert before the begin() cause we are back-tracing.
			copy.insert(copy.begin(), wordList[precursor2[i]]);
			generateRoute(copy, precursor[precursor2[i]], wordList);
		}
	
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		wordList.push_back(beginWord);
		int size = wordList.size();
		vector<int>* neighbors = new vector<int>[size];
		int ewordindex = -1;
		for (int i = 0; i < size; i++) {
			if (wordList[i] == endWord)
				ewordindex = i;
			for (int j = i + 1; j < size; j++) {
				if (isANeighbor(wordList[i],wordList[j])) {
					neighbors[i].push_back(j);
					neighbors[j].push_back(i);
				}
			}
		}
		vector<int> steps(size);//memorize distances
		queue<int> line;//BFS
		steps[size - 1] = 1;
		line.push(size - 1);//add the index of the beginWord to the queue
		precursor = new vector<int>[size];
		while (!line.empty()) {
			int pos = line.front();
			line.pop();
			if (wordList[pos] == endWord)
				//we stop here because we are looking for the shortest routes
				break;
			for (int i = 0; i < neighbors[pos].size(); i++) {
				if (steps[neighbors[pos][i]]==0) {
					//we have never visited here
					steps[neighbors[pos][i]] = steps[pos] + 1;
					precursor[neighbors[pos][i]].push_back(pos);
					line.push(neighbors[pos][i]);
				}
				else if (steps[neighbors[pos][i]] == steps[pos] + 1)
					//there's another route to get here and it has the SAME distance
					precursor[neighbors[pos][i]].push_back(pos);
			}
		
		}
		if (ewordindex == -1 || steps[ewordindex] == 0)
			return res;
		vector<string> right{endWord};
		generateRoute(right,precursor[ewordindex] , wordList);
		return res;
    }
//     vector<vector<string>>  ans;    //Stores all possible paths
    
//     void DFS(string& beginWord, string& endWord, unordered_map<string, unordered_set<string>>& adj, vector<string> &path) {
//         path.push_back(beginWord);  //Push current word
//         if(beginWord == endWord)
//         {
//             ans.push_back(path);
//             path.pop_back();
//             return;
//         }
//         for(auto x : adj[beginWord])
//             DFS(x, endWord, adj, path);
        
//         path.pop_back();    //Pop current word to Backtrack
//     }
    
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_map<string, unordered_set<string>> adj;   //Adjacency List
//         unordered_set<string> dict(wordList.begin(),wordList.end());   //Insert WordList in SET
        
//         //STEP-1: Find min-depth using BFS
//         queue<string> Q;    //For BFS traversal
//         Q.push(beginWord);  //Push start node (beginWord)
//         unordered_map<string, int> visited; //Key->String (Node)...Value->Level (Depth of traversal)
//         visited[beginWord] = 0; //Start node will always be at level 0
//         while(!Q.empty())
//         {
//             string curr = Q.front();
//             Q.pop();
//             string temp = curr;
//             for(int i = 0; i < curr.size(); ++i)    //For all characters
//             {
//                 for(char x = 'a'; x <= 'z'; ++x)    //Try all possible 26 letters
//                 {
//                     if(temp[i] == x)    //Skip if letter is same as in original word
//                         continue;

//                     temp[i] = x;    
//                     if(dict.count(temp) > 0)    //Check if new word is present in wordList
//                     {
//                         if(visited.count(temp) == 0)    //check if the new word was already visited
//                         {
//                             visited[temp] = visited[curr] + 1;
//                             Q.push(temp);
//                             adj[curr].insert(temp);
//                         } 
//                         else if(visited[temp] == visited[curr] + 1) //If already visited and new word is the child (We should always move down)
//                             adj[curr].insert(temp);
//                     }
//                 }
//                 temp[i] = curr[i];  //Revert back temp to curr
//             }
//         }
//         //STEP-2: Find all possible paths at min-depth using DFS
//         vector<string> path;
//         DFS(beginWord, endWord, adj, path); //Find all possible paths with min-depth
//         return ans; 
//     }
};