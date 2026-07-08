class Solution {
  public:
    bool sum_present(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp){
        if(sum==0) return true;
        if(idx==arr.size() || sum<0) return false;
        if(dp[idx][sum]!= -1) return dp[idx][sum];
        bool pick= sum_present(idx+1, sum-arr[idx], arr, dp);
        bool not_pick= sum_present(idx+1, sum, arr, dp);
        return dp[idx][sum]= (pick||not_pick);
    }
    int minDifference(vector<int>& arr) {
        int n= arr.size();
        int sum= 0;
        for(int i=0; i<n; i++) sum+= arr[i];
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        for (int i=sum/2; i>=0; i--) {
            if (sum_present(0,i,arr,dp)) return sum-2*i;
        }
        return sum;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna