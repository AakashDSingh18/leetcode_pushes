class Solution {
  public:
    int find_max(int curr, int C, vector<vector<int>>& dp, vector<int> &price, int& n){
        if(curr==n || C<0){
            return INT_MIN;
        }
        if(dp[curr][C]!= -1) return dp[curr][C];
        int not_pick= find_max(curr+1, C, dp, price, n);
        int pick= find_max(0, C-curr-1, dp, price, n) + price[curr];
        return dp[curr][C]= max(not_pick, pick);
    }
    int cutRod(vector<int> &price) {
        int n= price.size();
        int C= n;
        vector<vector<int>> dp(n, vector<int>(C+1, -1));
        for(int i=0; i<n; i++){
            dp[i][0]= 0;
        }
        return find_max(0, C, dp, price, n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna