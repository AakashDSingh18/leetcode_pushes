class Solution {
public:
    int findall(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& triangle, int& m){
        if(r==m) return INT_MAX;
        if(dp[r][c]!= INT_MAX) return dp[r][c];
        if(r==m-1) return dp[r][c]= triangle[r][c];
        int down1 = findall(r+1, c, dp, triangle, m);
        int down2 = findall(r+1, c+1, dp, triangle, m);
        return dp[r][c]= min(down1,down2) + triangle[r][c];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m= triangle.size();
        int n= triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX));
        return findall(0, 0, dp, triangle, m);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna