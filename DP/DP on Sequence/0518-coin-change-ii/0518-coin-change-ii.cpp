class Solution {
public:
    int func(int amount, vector<int>& coins, int idx, vector<vector<int>>& dp){
        if(amount<0) return 0;
        if(idx==-1) return (amount==0)? 1: 0;
        if(dp[idx][amount]!= -1) return dp[idx][amount];
        int not_pick= func(amount, coins, idx-1, dp);
        int pick= func(amount-coins[idx], coins, idx, dp);
        return dp[idx][amount]= not_pick + pick; 
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return func(amount, coins, n-1, dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna