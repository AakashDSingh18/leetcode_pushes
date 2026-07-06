class Solution {
  public:
  int timer= 1;
    void dfs(vector<vector<int>>& graph, vector<int>& visited, int curr, int pare, vector<int>& low, vector<int>& tin, vector<vector<int>>& ans){
        visited[curr]= 1;
        tin[curr]= timer;
        low[curr]= timer;
        timer++;
        for(int i=0; i<graph[curr].size(); i++){
            if(graph[curr][i]== pare) continue;
            if(!visited[graph[curr][i]]){
                dfs(graph, visited, graph[curr][i], curr, low, tin, ans);
                low[curr]= min(low[curr], low[graph[curr][i]]);
                if(low[graph[curr][i]] > tin[curr]){
                    ans.push_back({graph[curr][i], curr});
                }
            }else{
                low[curr]= min(low[curr], tin[graph[curr][i]]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>());
        vector<vector<int>> ans;
        for(int i=0; i<connections.size(); i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<int> visited(n, 0);
        dfs(graph, visited, 0, -1, low, tin, ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna