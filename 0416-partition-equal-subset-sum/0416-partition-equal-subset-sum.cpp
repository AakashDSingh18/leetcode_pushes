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
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum= 0;
        for(int i=0; i<n; i++) sum+= nums[i];
        if(sum&1) return false;
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        return sum_present(0, sum/2, nums, dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna