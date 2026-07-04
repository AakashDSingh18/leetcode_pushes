class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int n= edges.size();
        vector<int> shortest(V, 1e8);
        shortest[src]= 0;
        for(int i=0; i<V-1; i++){
            for(int j=0; j<n; j++){
                if((shortest[edges[j][0]]!=1e8) && (shortest[edges[j][0]]+edges[j][2] < shortest[edges[j][1]])){
                    // if(shortest[edges[j][0]]+edges[j][2] < 0) return {-1};
                    shortest[edges[j][1]]= shortest[edges[j][0]]+edges[j][2];
                }
            }
        }
        for(int j=0; j<n; j++){
            if(shortest[edges[j][0]]!=1e8 && shortest[edges[j][0]]+edges[j][2] < shortest[edges[j][1]]){
                return {-1};
            }
        }
        return shortest;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna