class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n= nums.size();
        vector<long long> preGcd(n, 0);
        int maxi= nums[0];
        for(int i=0; i<n; i++){
            maxi= max(maxi, nums[i]);
            preGcd[i]= gcd(nums[i], maxi);
        }
        sort(preGcd.begin(), preGcd.end());
        int i=0; 
        int j= n-1;
        long long ans=0;
        while(i<j){
            ans+= gcd(preGcd[i], preGcd[j]);
            i++, j--;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna