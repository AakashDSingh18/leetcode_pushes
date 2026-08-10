class Solution {
public:
    bool checkall(int n, vector<vector<int>>& dp, int turn){
        if(n==0) return false;
        if(dp[n][turn]!= -1) return dp[n][turn];
        int i= sqrt(n);
        if(i*i==n) return dp[n][turn]= true;
        for(int j=1; j*j< n; j++){
            bool ans=(checkall(n-(j*j), dp, !turn))? false: true;
            if(ans) return dp[n][turn]= true;
        }
        return dp[n][turn]= false;
    }
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return checkall(n, dp, 0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna