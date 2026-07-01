class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>());
        int n= edges.size();
        for(int i=0; i<n; i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> shortest(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, src});
        shortest[src]= 0;
        while(!q.empty()){
                int curr= q.top().second;
                int wt= q.top().first;
                q.pop();
                for(int i=0; i<graph[curr].size(); i++){
                    if(wt+graph[curr][i].second < shortest[graph[curr][i].first]){
                        shortest[graph[curr][i].first]= wt+graph[curr][i].second;
                        q.push({shortest[graph[curr][i].first], graph[curr][i].first});
                    }
                }
        }
        return shortest;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna