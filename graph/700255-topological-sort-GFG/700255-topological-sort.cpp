class Solution {
  public:
    // void dfs(vector<vector<int>>& edges, int curr, stack<int>& track, vector<int>& visited){
    //     visited[curr]=1;
    //     for(int i=0; i<edges[curr].size(); i++){
    //         if(!visited[edges[curr][i]]) dfs(edges, edges[curr][i], track, visited);
    //     }
    //     track.push(curr);
    // }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        //// Using DSF
        // stack<int> track;
        // vector<int> ans;
        // vector<int> visited(V, 0);
        // vector<vector<int>> edge(V, vector<int>());
        // int n= edges.size();
        // for(int i=0; i<n; i++){
        //     edge[edges[i][0]].push_back(edges[i][1]);
        // }
        
        // for(int i=0; i<V; i++){
        //     if(!visited[i]){
        //         dfs(edge, i, track, visited);
        //     }
        // }
        // while(!track.empty()){
        //     ans.push_back(track.top());
        //     track.pop();
        // }
        // return ans;
        
        
        //// Using Modified BSF
        vector<int> indegree(V, 0);
        int n= edges.size();
        for(int i=0; i<n; i++){
            indegree[edges[i][1]]++;
        }
        vector<vector<int>> edge(V, vector<int>());
        for(int i=0; i<n; i++){
            edge[edges[i][0]].push_back(edges[i][1]);
        }
        queue<int> track;
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                track.push(i);
                ans.push_back(i);
            }
        }
        while(!track.empty()){
            int curr= track.front();
            track.pop();
            for(int i=0; i<edge[curr].size(); i++){
                indegree[edge[curr][i]]--;
                if(indegree[edge[curr][i]]==0){
                    track.push(edge[curr][i]);
                    ans.push_back(edge[curr][i]);
                }
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna