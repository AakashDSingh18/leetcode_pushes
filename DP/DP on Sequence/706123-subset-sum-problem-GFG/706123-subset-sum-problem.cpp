class Solution {
  public:
    bool sum_present(int idx, int sum, vector<int>& arr, vector<bool>& dp){
        if(sum==0) return true;
        if(idx==arr.size() || sum<0) return false;
        if(dp[idx]) return true;
        bool pick= sum_present(idx+1, sum-arr[idx], arr, dp);
        bool not_pick= sum_present(idx+1, sum, arr, dp);
        return dp[idx]= (pick||not_pick);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n= arr.size();
        vector<bool> dp(n, false);
        return sum_present(0, sum, arr, dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna