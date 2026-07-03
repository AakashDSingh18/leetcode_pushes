class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        vector<int> dist={1, 0, -1, 0, 1, 1, -1, -1 ,1};
        int n= grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        q.push({{0,0}, 1});
        visited[0][0]= 1;
        while(!q.empty()){
            int cr= q.front().first.first;
            int cc= q.front().first.second;
            int wt= q.front().second;
            q.pop();
            for(int i=0; i<8; i++){
                int nr= cr+dist[i];
                int nc= cc+dist[i+1];
                if(nr==n-1 && nc==n-1) return wt+1;
                if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    if(!visited[nr][nc] && grid[nr][nc]==0){
                        visited[nr][nc]=1;
                        q.push({{nr, nc}, wt+1});
                    }
                }
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna