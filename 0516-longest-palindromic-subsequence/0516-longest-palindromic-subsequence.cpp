class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s2= s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]!= -1) continue;
                if(s[i]==s2[j]){
                    dp[i][j]= 1+ ((i-1>=0 && j-1>=0)? dp[i-1][j-1]: 0);
                }else{
                    int skip1= ((j-1>=0)? dp[i][j-1]: 0);
                    int skip2= ((i-1>=0)? dp[i-1][j]: 0);
                    dp[i][j]= max(skip1, skip2);
                }
            }
        }
        return dp[n-1][n-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna