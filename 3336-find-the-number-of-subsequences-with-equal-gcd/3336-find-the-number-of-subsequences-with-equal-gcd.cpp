class Solution {
public:
    int mod= 1e9+7;
    int findall(int idx, int Gcd1, int Gcd2, vector<int>& nums, vector<vector<vector<int>>>& dp){
        if(idx < 0){
            if(Gcd1==Gcd2 && Gcd1!=0) return 1;
            return 0;
        }
        if(dp[idx][Gcd1][Gcd2]!= -1) return dp[idx][Gcd1][Gcd2];
        long long skip= findall(idx-1, Gcd1, Gcd2, nums, dp);
        long long add_1= findall(idx-1, gcd(Gcd1, nums[idx]), Gcd2, nums, dp);
        long long add_2= findall(idx-1, Gcd1, gcd(Gcd2, nums[idx]), nums, dp);
        return dp[idx][Gcd1][Gcd2]= (skip+add_1+add_2)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n= nums.size();
        int mod= 1e9+7;
        int m= *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m+1, vector<int>(m+1, -1)));
        return findall(n-1, 0, 0, nums, dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna