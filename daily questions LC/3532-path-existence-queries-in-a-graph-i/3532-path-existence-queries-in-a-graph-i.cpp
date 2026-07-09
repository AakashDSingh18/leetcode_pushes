class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int m= queries.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        vector<bool> ans;
        for(int i=0; i<n-1; i++){
            if(abs(nums[i]-nums[i+1]) <= maxDiff){
                parent[i+1]= parent[i];
            }
        }
        for(int i=0; i<m; i++){
            if( parent[queries[i][0]] == parent[queries[i][1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna