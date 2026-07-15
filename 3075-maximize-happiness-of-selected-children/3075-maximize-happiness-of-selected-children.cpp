class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long ans=0;
        int temp=0;
        int i= happiness.size()-1;
        while(k>0){
            ans+= (happiness[i]-temp>=0)?(happiness[i]-temp): 0;
            temp++;
            k--;
            i--;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna