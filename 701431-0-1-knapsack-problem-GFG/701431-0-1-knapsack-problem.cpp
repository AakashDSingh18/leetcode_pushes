class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n= val.size();
        vector<int> dp(W+1, 0);
        for(int i=wt[0]; i<=W; i++){
            dp[i]= val[0];
        }
        for(int i=1; i<n; i++){
            for(int j=W; j>=0; j--){
                int not_pick= dp[j];
                int pick= (j-wt[i] >= 0)? dp[j-wt[i]] + val[i]: 0;
                dp[j]= max(not_pick, pick);
            }
        }
        return dp[W];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna