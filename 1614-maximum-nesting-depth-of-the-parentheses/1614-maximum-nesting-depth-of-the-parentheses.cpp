class Solution {
public:
    int maxDepth(string s) {
        // stack<int> ans;
        int ans=0;
        int count=0;
        for(auto i: s){
            if(i=='('){
                count++;
                ans=max(ans,count);
            }
            else if(i==')') count--;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna