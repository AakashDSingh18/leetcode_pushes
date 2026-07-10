class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n= s1.size();
        int m= s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxi= 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dp[i][j]!= -1) continue;
                if(s1[i]==s2[j]){
                    dp[i][j]=1+ ((i-1>=0 && j-1>=0)? dp[i-1][j-1]: 0);
                    maxi=max(maxi, dp[i][j]);
                }else {
                    dp[i][j]= 0;
                }
            }
        }
        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna