class Solution {
public:
    int digitr(int num){
        int maxi= INT_MIN;
        int mini= INT_MAX;
        while(num){
            maxi= max(maxi, num%10);
            mini= min(mini, num%10);
            num/=10;
        }
        return (maxi-mini);
    }
    int maxDigitRange(vector<int>& nums) {
        int n= nums.size();
        // priority_queue<pair<int, int>> freq;
        int maxi= INT_MIN;
        for(int i=0; i<n; i++){
            maxi= max(maxi, digitr(nums[i]));
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(maxi==digitr(nums[i])){
                ans+= nums[i];
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna