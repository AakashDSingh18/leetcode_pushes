class Solution {
public:
    bool hasCycle(vector<vector<int>>& edges, vector<int>& visited, int curr, vector<int> currvisited){
        currvisited[curr]= 1;
        visited[curr]= 1;
        for(int i=0; i<edges[curr].size(); i++){
            if(!currvisited[edges[curr][i]]){
                if(!visited[edges[curr][i]]){
                    if(hasCycle(edges, visited, edges[curr][i], currvisited)) return true;
                }
            }else{
                return true;
            }
        }
        currvisited[curr]= 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses, vector<int>());
        vector<int> currvisited(numCourses, 0);
        vector<int> visited(numCourses, 0);
        int n= prerequisites.size();
        for(int i=0; i<n; i++){
            edge[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0; i<numCourses; i++){
            if(!visited[i]) if(hasCycle(edge, visited, i, currvisited)) return false;
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna