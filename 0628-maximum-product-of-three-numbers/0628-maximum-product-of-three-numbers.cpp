class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        return max(nums[0]*nums[1]*nums[2], 
                    max(nums[n-1]*nums[n-2]*nums[n-3], 
                    max(nums[0]*nums[n-1]*nums[n-2],
                    nums[0]*nums[1]*nums[n-1])));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna