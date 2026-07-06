class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        unordered_map<int, int> pre;
        int n= nums.size();
        // int i=0;
        int ans= INT_MIN;
        int maxi= INT_MIN;
        for(int i=0; i<n; i++){
            if(pre.find(i-k)!= pre.end()){
                ans= max(ans, pre[i-k]+nums[i]);
            }
            maxi= max(nums[i], maxi);
            pre[i]= maxi;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna