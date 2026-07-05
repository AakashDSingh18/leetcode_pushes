class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n= nums.size();
        int num= nums[n/2];
        int cnt=0;
        for(int i=0; i<n; i++){
            if(num== nums[i]) cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna