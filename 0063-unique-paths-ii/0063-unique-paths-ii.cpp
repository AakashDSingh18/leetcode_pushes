class Solution {
public:
    int findall(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid, int& m, int& n){
        if(r==m || c==n || obstacleGrid[r][c]==1) return 0;
        if(dp[r][c]!= -1) return dp[r][c];
        if(r==m-1 && c==n-1) return dp[r][c]=1;
        int right= findall(r, c+1, dp, obstacleGrid, m, n);
        int down = findall(r+1, c, dp, obstacleGrid, m, n);
        return dp[r][c]= right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findall(0, 0, dp, obstacleGrid, m, n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna