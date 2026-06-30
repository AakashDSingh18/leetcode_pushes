class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans=0;
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int i=n-1;
        while(i>=0 && k--){
            ans+= ((long long)nums[i]*mul);
            if(mul>1) mul--;
            i--;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna