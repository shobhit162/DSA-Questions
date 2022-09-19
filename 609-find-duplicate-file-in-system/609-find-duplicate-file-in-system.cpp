class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        	unordered_map<string, vector<string>> Files;
	vector<vector<string> > ans;
	for(auto& path : paths) {
		int i = 0, j;
		while(path[i] != ' ') i++;      // all characters till first space form the directory
		string dir = path.substr(0, i), file, content;
		while(i++ < size(path)) {
			// all characters after space till the opening bracket form file name
			j = i;
			while(path[i] != '(') i++;  
			file = path.substr(j, i - j);
			// all characters after opening bracket till closing bracket form file content
			j = i;
			while(path[i++] != ')');    
			content = path.substr(j, i - j);
			// map the file content to the directory of the file
			Files[content].emplace_back(dir + '/' + file);
		}
	}
	for(auto& content : Files) 
		if(size(content.second) > 1)
			ans.push_back(move(content.second));
	return ans;
    }
};