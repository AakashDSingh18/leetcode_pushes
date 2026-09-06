class Solution {
public:
    int findall(int i, int j, int& n, int& m, string s, string t, vector<vector<int>>& dp){
        if(n-i < m-j) return 0;
        if(j==m) return 1;
        if(i==n) return (j==m)? 1: 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int n_pick= findall(i+1, j, n, m, s, t, dp);
        int pick= (s[i]==t[j])? findall(i+1, j+1, n, m, s, t, dp): 0;
        return dp[i][j]= n_pick+pick;
    }
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return findall(0, 0, n, m, s, t, dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna