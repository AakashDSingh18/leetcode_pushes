class Solution {
public:
    int checkall(vector<int>& nums, int i, int j){
        if(i>j){
            return 0;
        }
        int pick_left= nums[i]-checkall(nums, i+1, j);
        int pick_right = nums[j] - checkall(nums, i, j-1);
        return max(pick_left, pick_right);
    }
    bool predictTheWinner(vector<int>& nums) {
        if(!(nums.size()&1)) return true;
        return checkall(nums,0,nums.size()-1) >= 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna