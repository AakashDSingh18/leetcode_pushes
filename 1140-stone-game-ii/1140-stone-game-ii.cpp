class Solution {
public:
    int findall(int curr, int m, int turn, vector<vector<vector<int>>>& dp, vector<int>& piles){
        if(curr==piles.size()) return 0;
        if(dp[curr][m][turn]!= -1) return dp[curr][m][turn];
        int pick= (turn==0)? 0: 1e9;
        int current_value= 0;
        for(int i= curr; i-curr<2*m && i<piles.size(); i++){
            current_value+= piles[i];
            if(turn==0) pick= max(pick, current_value+findall(i+1, max(m, i-curr+1), 1, dp, piles));
            else pick= min(pick, findall(i+1, max(m, i-curr+1), 0, dp, piles));
        }
        return dp[curr][m][turn]= pick;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(105, vector<int>(2, -1)));
        return findall(0, 1, 0, dp, piles);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna