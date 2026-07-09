//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        if(n<=1) return 0;
        vector<int> dp(n, -1);
        for(int i=0; i<n; i++){
            if(i<=1) dp[i]=cost[i];
            else dp[i]= min(dp[i-1], dp[i-2])+cost[i];
        }
        return min(dp[n-1], dp[n-2]);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna