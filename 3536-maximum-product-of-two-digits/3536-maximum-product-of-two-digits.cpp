class Solution {
public:
    int maxProduct(int n) {
        // priority_queue<int> q;
        // unordered_map<int, int> mpp;
        vector<int> freq(10, 0);
        while(n){
            freq[n%10]++;
            n/=10;
        }
        for(int i=9; i>=0; i--){
            if(freq[i]>0){
                int num1= i;
                if(freq[i]>1) return num1*num1;
                i--;
                while(i>=0 && freq[i]==0) i--;
                return num1*i;
            } 
        }
        return 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna