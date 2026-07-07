class Solution {
  public:
    void dfs(stack<int>& finish, vector<int>& visited, vector<vector<int>>& graph, int node){
        visited[node]=1;
        for(int i=0; i<graph[node].size(); i++){
            if(!visited[graph[node][i]]){
                dfs(finish, visited, graph, graph[node][i]);
            }
        }
        finish.push(node);
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<vector<int>> graph(V, vector<int>());
        int n= edges.size();
        vector<int> visited(V, 0);
        for(int i=0; i<n; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        stack<int> finish;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(finish, visited, graph, i);
            }
        }
        vector<vector<int>> graphnew(V, vector<int>());
        for(int i=0; i<n; i++){
            graphnew[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> newvisited(V, 0);
        stack<int> finishnew;
        int ans =0;
        while(!finish.empty()){
            int curr= finish.top();
            finish.pop();
            if(!newvisited[curr]){
                dfs(finishnew, newvisited, graphnew, curr);
                ans++;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna