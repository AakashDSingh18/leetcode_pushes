class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int ans= nums[0]+nums[1]+nums[2];
        for(int i=1; i<n-1; i++){
            int l=0;
            int r=n-1;
            while(i>l && i<r){
                int curr_sum= nums[i]+nums[l]+nums[r];
                if(target-curr_sum == 0) return curr_sum;
                else if(target-curr_sum > 0){
                    if(abs(target-ans) > abs(target-curr_sum)) ans= curr_sum;
                    l++;
                }else{
                    if(abs(target-ans) > abs(target-curr_sum)) ans= curr_sum;
                    r--;
                }
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna