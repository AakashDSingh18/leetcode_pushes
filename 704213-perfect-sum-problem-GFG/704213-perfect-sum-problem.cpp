class Solution {
  public:
    int sum_present(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp){
        // if(sum==0) return true;
        if(idx==arr.size() && sum==0) return 1;
        if(idx==arr.size() || sum<0) return 0;
        if(dp[idx][sum]!= -1) return dp[idx][sum];
        int pick= sum_present(idx+1, sum-arr[idx], arr, dp);
        int not_pick= sum_present(idx+1, sum, arr, dp);
        return dp[idx][sum]= (pick+not_pick);
    }
    int perfectSum(vector<int>& arr, int target) {
        int n= arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return sum_present(0, target, arr, dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna