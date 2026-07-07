class Solution {
  public:
    int minCost(vector<int>& height) {
        // Tabulated method of DP
        int n= height.size();
        vector<int> dp(n, -1);
        dp[0]=0;
        dp[1]=abs(height[1]-height[0]);
        for(int i=2; i<n; i++){
            dp[i]= min(dp[i-1]+abs(height[i]-height[i-1]), dp[i-2]+abs(height[i]-height[i-2]));
        }
        return dp[n-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna