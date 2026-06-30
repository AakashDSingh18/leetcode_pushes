class Solution {
  public:
    vector<int>shortestPath(int V,vector<vector<int>> &edges,int src) {
        vector<vector<int>> edge(V,vector<int>());
        int n= edges.size();
        for(int i= 0;i< n;i++){
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> shortest(V, -1);
        queue<int> q;
        shortest[src]= 0;
        q.push(src);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i= 0; i<edge[curr].size() ; i++){
                int neighbor= edge[curr][i];
                if(shortest[neighbor]== -1){
                    shortest[neighbor]= shortest[curr] +1;
                    q.push(neighbor);
                }
            }
        }
        return shortest;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna