class Solution {
  public:
    int sum_present(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp){
        if(idx==arr.size() && sum==0) return 1;
        if(idx==arr.size() || sum<0) return 0;
        if(dp[idx][sum]!= -1) return dp[idx][sum];
        int pick= sum_present(idx+1, sum-arr[idx], arr, dp);
        int not_pick= sum_present(idx+1, sum, arr, dp);
        return dp[idx][sum]= (pick+not_pick);
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n= arr.size();
        int sum= 0;
        for(int i=0; i<n; i++) sum+= arr[i];
        sum-=diff;
        if(sum&1 || sum<0) return 0;
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        // int ans=0;
        int temp= sum_present(0,sum/2,arr,dp);
        return temp;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna