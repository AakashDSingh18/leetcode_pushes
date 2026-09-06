class Solution {
public:
    // MEMOIZATION
    // int findall(int i, int j, int& n, int& m, string s, string t, vector<vector<int>>& dp){
    //     if(n-i < m-j) return 0;
    //     if(j==m) return 1;
    //     if(i==n) return (j==m)? 1: 0;
    //     if(dp[i][j]!= -1) return dp[i][j];
    //     int n_pick= findall(i+1, j, n, m, s, t, dp);
    //     int pick= (s[i]==t[j])? findall(i+1, j+1, n, m, s, t, dp): 0;
    //     return dp[i][j]= n_pick+pick;
    // }
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // return findall(0, 0, n, m, s, t, dp);

        // TABULATION
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1, 0));
        for(int i=0; i<=n; i++) dp[i][m]= 1;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s[i]==t[j]) dp[i][j]+= dp[i+1][j+1];
                dp[i][j]+= dp[i+1][j];
            }
        }
        return dp[0][0];        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna