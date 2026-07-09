class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));
        for(int i=0; i<n; i++){
            for(int j=0; j<=amount; j++){
                if(j==0){
                    dp[i][j]= 0;
                    continue;
                }
                if(i==0){
                    if(j%coins[i]==0) dp[i][j]= j/coins[i];
                    else dp[i][j]= 1e9;
                    continue;
                }
                // if(dp[i][j]!= 1e9) continue; 
                int not_pick= dp[i-1][j];
                int pick= (j-coins[i] >= 0)? 1 + dp[i][j-coins[i]]: 1e9;
                dp[i][j]= min(not_pick, pick);
            }
        }
        return (dp[n-1][amount] < 1e9)? dp[n-1][amount]: -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna