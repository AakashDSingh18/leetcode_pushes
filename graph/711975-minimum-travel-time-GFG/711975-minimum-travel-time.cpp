class Solution {
  public:
    int Solve(int n, vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        // int n= grid.size();
        vector<vector<int>> shortest(n, vector<int>(n, INT_MAX));
        q.push({grid[0][0], {0,0}});
        shortest[0][0]= grid[0][0];
        vector<int> dist= {1, 0, -1, 0 ,1};
        while(!q.empty()){
                int cr= q.top().second.first;
                int cc= q.top().second.second;
                int wt= q.top().first;
                q.pop();
                for(int k=0; k<4; k++){
                    int nr= cr+ dist[k];
                    int nc= cc+ dist[k+1];
                    if(nr<n && nr>=0 && nc<n && nc>=0 && shortest[nr][nc]> max(grid[nr][nc], wt)){
                        shortest[nr][nc]= max(grid[nr][nc], wt);
                        q.push({max(grid[nr][nc], wt), {nr, nc}});
                    }
                }
        }
        return shortest[n-1][n-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna