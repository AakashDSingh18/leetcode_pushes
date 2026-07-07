class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans= 0;
        string num= to_string(n);
        long long sum= 0;
        for(auto& x: num){
            int temp= (x-48);
            if(x!='0') ans= (ans*10)+temp;
            sum+= temp;
        }
        return ans*sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna