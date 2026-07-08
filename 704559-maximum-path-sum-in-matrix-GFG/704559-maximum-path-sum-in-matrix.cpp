class Solution {
  public:
    int maximumPath(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        vector<int> dp(m, -1);
        for(int i=0; i<m; i++){
            dp[i]= mat[0][i];
        }
        for(int i=1; i<n; i++){
            vector<int> temp(m, -1);
            for(int j=0; j<m; j++){
                int behind= (j-1>=0)? dp[j-1]: 0;
                int mid= dp[j];
                int front= (j+1<m)? dp[j+1]: 0;
                temp[j]= max(behind, max(mid, front))+ mat[i][j];
            }
            dp= temp;
        }
        int ans=INT_MIN;
        for(int i=0; i<m; i++){
            ans= max(ans, dp[i]);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna