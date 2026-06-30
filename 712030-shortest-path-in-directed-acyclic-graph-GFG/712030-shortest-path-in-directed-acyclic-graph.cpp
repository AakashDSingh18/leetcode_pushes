class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V, vector<int>(V, -1));
        int n= edges.size();
        vector<int> shortest(V, -1);
        for(int i=0; i<n; i++){
            adj[edges[i][0]][edges[i][1]]= edges[i][2];
        }
        queue<pair<int, int>> q;
        vector<int> visited(V, 0);
        q.push({0, 0});
        shortest[0]= 0;
        while(!q.empty()){
            int temp= q.size();
            while(temp--){
                int curr= q.front().first;
                int wt= q.front().second;
                q.pop();
                for(int i=0; i<V; i++){
                    if(adj[curr][i]!= -1) { 
                         if(shortest[i]== -1 || wt+adj[curr][i]< shortest[i]) {
                            shortest[i] = wt + adj[curr][i];
                            q.push({i, shortest[i]});
                        }
                    }
                }
            }
        }
        return shortest;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna