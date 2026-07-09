class Solution {
public:
    int findall(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& Grid, int& m, int& n){
        if(r==m || c==n) return 10000000;
        if(dp[r][c]!= -1) return dp[r][c];
        if(r==m-1 && c==n-1) return dp[r][c]= Grid[r][c];
        int right= findall(r, c+1, dp, Grid, m, n);
        int down = findall(r+1, c, dp, Grid, m, n);
        return dp[r][c]= min(right,down)+ Grid[r][c];
    }
    int minPathSum(vector<vector<int>>& Grid) {
        int m= Grid.size();
        int n= Grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findall(0, 0, dp, Grid, m, n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna