class Solution {
public:
    int target_cnt(vector<int>& nums, int target, int idx, int& n, vector<vector<int>>& dp){
        if(idx==n){
            if(target==0) return 1;
            else return 0;
        }
        if(abs(target) > 1000) return 0;
        if(dp[idx][target+1000]!= -1) return dp[idx][target+1000];
        int diff_pick= target_cnt(nums, target+nums[idx], idx+1, n, dp);
        int add_pick= target_cnt(nums, target-nums[idx], idx+1, n, dp);
        return dp[idx][target+1000]= (diff_pick + add_pick);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> dp(n, vector<int>(2000+1, -1));
        return target_cnt(nums, target, 0, n, dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna