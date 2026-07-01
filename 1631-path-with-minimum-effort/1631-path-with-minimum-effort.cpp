class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size();
        int m= heights[0].size();
        vector<int> dist={1, 0, -1, 0, 1};
        vector<vector<int>> shortest(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        q.push({0, {0,0}});
        shortest[0][0] = 0;
        while(!q.empty()){
            int cr= q.top().second.first;
            int cc= q.top().second.second;
            int wt= q.top().first;
            q.pop();
            for(int i=0; i<4; i++){
                int nc= cc+dist[i+1];
                int nr= cr+dist[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    if(shortest[nr][nc] > max(abs(heights[cr][cc]-heights[nr][nc]), wt)){
                        shortest[nr][nc]= max(abs(heights[cr][cc]-heights[nr][nc]), wt);
                        q.push({max(abs(heights[cr][cc]-heights[nr][nc]), wt), {nr, nc}});
                    }
                }
            }
        }
        return shortest[n-1][m-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna