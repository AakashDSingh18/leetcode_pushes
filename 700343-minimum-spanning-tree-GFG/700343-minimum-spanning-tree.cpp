class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>());
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> visited(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        int ans= 0;
        while(!q.empty()){
            int curr= q.top().second;
            int wt= q.top().first;
            q.pop();
            if(visited[curr]) continue;
            visited[curr]= 1;
            ans+= wt;
            for(int i=0; i<graph[curr].size(); i++){
                if(!visited[graph[curr][i].first]){
                    q.push({graph[curr][i].second, graph[curr][i].first});
                }
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna