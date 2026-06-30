class Solution {
  public:
    void go_deep(vector<vector<int>>& adj, vector<int>& visited, int node, vector<int>& ans){
        ans.push_back(node);
        for(auto x: adj[node]){
            if(!visited[x]){
                visited[x]=1;
                go_deep(adj, visited, x, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans;
        int n= adj.size();
        vector<int> visited(n, 0);
        int node= 0;
        visited[0]= 1;
        go_deep(adj, visited, node, ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna