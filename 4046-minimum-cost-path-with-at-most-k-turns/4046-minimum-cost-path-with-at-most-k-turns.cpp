class Solution {
public:
    int findall(int& m, int& n, vector<vector<int>>& grid, int& k, int turns, int curr, int i, int j, vector<vector<vector<vector<int>>>>& dp, int last){
        if(turns>k) return INT_MAX;
        if(i == m - 1 && j == n - 1) {
            return grid[m - 1][n - 1];
        }
        int temp= INT_MAX;
        if(dp[i][j][last][turns]!= -1){
            return dp[i][j][last][turns];
        }
        if(i+1<m) temp= min(temp, findall(m, n, grid, k, (last!=1 && last!=0)?turns+1: turns, curr+grid[i][j], i+1, j, dp, 1)); 
        if(j-1>=0) temp= min(temp, findall(m, n, grid, k, (last!=4 && last!=0)?turns+1: turns, curr+grid[i][j], i, j-1, dp, 4));
        if(j+1<n) temp= min(temp, findall(m, n, grid, k, (last!=3 && last!=0)?turns+1: turns, curr+grid[i][j], i, j+1, dp, 3));
        if(i-1>=0) temp= min(temp, findall(m, n, grid, k, (last!=2 && last!=0)?turns+1: turns, curr+grid[i][j], i-1, j, dp, 2));
        if(temp!=INT_MAX) {
            temp+=grid[i][j];
        }
        return dp[i][j][last][turns]= temp;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n= grid[0].size();
        int ans= INT_MAX;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<vector<vector<int>>>> dp(m, vector<vector<vector<int>>>(n, vector<vector<int>>(5, vector<int>(k+1,-1))));
        ans= findall(m, n, grid, k, 0, 0, 0, 0, dp, 0);
        return (ans==INT_MAX)? -1: ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna