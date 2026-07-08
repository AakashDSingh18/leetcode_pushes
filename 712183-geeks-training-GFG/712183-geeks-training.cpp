class Solution {
  public:
    int func(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& mat, int& n){
        if(r==-1) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int left= func(r-1, (c+1)%3, dp, mat,n);
        int right= func(r-1, (c+2)%3, dp, mat,n);
        return dp[r][c]= max(left, right)+mat[r][c];
    }
    int maximumPoints(vector<vector<int>>& mat) {
        int n= mat.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int ans= INT_MIN;
        for(int i=0; i<3; i++){
            ans= max(ans, func(n-1, i, dp, mat, n));
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna