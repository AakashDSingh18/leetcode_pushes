class Solution {
public:
    string largestOddNumber(string num) {
        int size= num.size();
        for(int i=size-1; i>=0; i--){
            int check= int(num[i]);
            if(check%2 != 0) return num.substr(0,i+1);
        }
        return "";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna