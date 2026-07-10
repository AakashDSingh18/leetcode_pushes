class Solution {
public:
    int find_max(int id1, int id2, string& text1, string& text2, vector<vector<int>>& dp){
        if(id1==-1 || id2==-1) return 0;
        if(dp[id1][id2]!= -1) return dp[id1][id2]; 
        if(text1[id1]==text2[id2]){
            return dp[id1][id2]= 1+find_max(id1-1, id2-1, text1, text2, dp);
        }else {
            int skip1= find_max(id1-1, id2, text1, text2, dp);
            int skip2= find_max(id1, id2-1, text1, text2, dp);
            return dp[id1][id2]= max(skip1, skip2);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();
        int id1= n-1;
        int id2= m-1;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return find_max(id1, id2, text1, text2, dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna