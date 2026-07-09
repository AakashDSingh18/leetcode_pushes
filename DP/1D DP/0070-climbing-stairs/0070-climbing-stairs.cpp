class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        for(int i=0; i<=n; i++){
            if(i<=1) dp[i]= 1;
            else dp[i]= dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna