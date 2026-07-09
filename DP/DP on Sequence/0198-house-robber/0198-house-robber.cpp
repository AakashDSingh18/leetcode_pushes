class Solution {
public:
    int rob(vector<int>& nums) {
    // Tabulation method {bottom - up}
        int n= nums.size();
        // vector<int> dp(n, -1);
        // dp[0]= nums[0];
        // if(n==1) return dp[0];
        // dp[1]= max(nums[0], nums[1]);
        // if(n==2) return dp[1];
        // for(int i=2; i<n; i++){
            // dp[i]= max(dp[i-2]+nums[i], dp[i-1]);
        // }
        // return dp[n-1];

    // Space Optimised Code
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        int a= 0;
        int b=0;
        int curr= 0;
        for(int i=0; i<n; i++){
            curr= max(a+nums[i], b);
            a= b;
            b= curr;
        }
        return curr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna