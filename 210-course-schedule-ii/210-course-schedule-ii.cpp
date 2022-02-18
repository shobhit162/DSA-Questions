class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>>graph(numCourses);
        vector<int>bfs;
        vector<int>degree(numCourses,0);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!degree[i])
            {
                bfs.push_back(i);
            }
        }
        
        for(int i=0;i<bfs.size();i++)
        {
            
            for(auto el:graph[bfs[i]])
            {
                degree[el]--;
                if(degree[el]==0)
                {
                    bfs.push_back(el);
                }
            }
        }
        vector<int>ans;
        return bfs.size()==numCourses?bfs:ans;
    }
};
