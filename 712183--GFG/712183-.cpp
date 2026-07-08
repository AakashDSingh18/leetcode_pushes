class Solution {
  public:
  // Memoization method
    // int func(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& mat, int& n){
    //     if(r==-1) return 0;
    //     if(dp[r][c]!=-1) return dp[r][c];
    //     int left= func(r-1, (c+1)%3, dp, mat,n);
    //     int right= func(r-1, (c+2)%3, dp, mat,n);
    //     return dp[r][c]= max(left, right)+mat[r][c];
    // }
    int maximumPoints(vector<vector<int>>& mat) {
        int n= mat.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        // int ans= INT_MIN;
        // for(int i=0; i<3; i++){
        //     ans= max(ans, func(n-1, i, dp, mat, n));
        // }
        // return ans;
        
        
        // Tabulation method
        int ans= INT_MIN;
        for(int r=0; r<n; r++){
            for(int c=0; c<3; c++){
                if(r==0) dp[r][c]= mat[r][c];
                else if(dp[r][c]!=-1) return dp[r][c];
                else {
                    int left= dp[r-1][(c+1)%3];
                    int right= dp[r-1][(c+2)%3];
                    dp[r][c]= max(left, right)+mat[r][c];
                }
            }
        }
        return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna