class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>graph (n, vector<int>(n, 1e8));
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]][edges[i][1]]= edges[i][2];
            graph[edges[i][1]][edges[i][0]]= edges[i][2];
        }
        for(int i=0; i<n; i++) graph[i][i]= 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(graph[j][i]!= 1e8 && graph[i][k]!= 1e8 && graph[j][i]+graph[i][k] < graph[j][k]){
                        graph[j][k]= graph[j][i]+graph[i][k];
                    }
                }
            }
        }
        int mini= INT_MAX;
        int ans= 0;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(graph[i][j]<=distanceThreshold) cnt++;
            }
            if(mini >= cnt){
                ans= i;
                mini= cnt;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna