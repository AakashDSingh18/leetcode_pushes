class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            if(ans[ans.size()-1][0] >= intervals[i][0] && ans[ans.size()-1][1] <= intervals[i][1]){
                ans[ans.size()-1]= intervals[i];
            }else if(ans[ans.size()-1][0]<= intervals[i][0] && ans[ans.size()-1][1] >= intervals[i][1]){
                continue;
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna