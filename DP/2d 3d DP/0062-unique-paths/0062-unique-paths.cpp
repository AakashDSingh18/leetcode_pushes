class Solution {
public:
//Memoization method
    // int findall(int r, int c, int& m, int& n, vector<vector<int>>& dp){
    //     if(r==m-1 && c==n-1) return 1;
    //     if(r==m || c==n) return 0;
    //     if(dp[r][c]!= -1) return dp[r][c];
    //     int right = findall(r, c+1, m, n, dp);
    //     int bottom= findall(r+1, c, m, n, dp);
    //     return dp[r][c]= right+bottom;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return findall(0, 0, m, n, dp);

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i==m-1 && j==n-1) dp[i][j]= 1;
                // else if(j+1>=n || i+1>=m) continue;
                else{
                    int right= (j+1 < n)? dp[i][j+1]: 0;
                    int left= (i+1 < m)? dp[i+1][j]: 0;
                    dp[i][j]= right+left;
                }
            }
        }
        return dp[0][0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna