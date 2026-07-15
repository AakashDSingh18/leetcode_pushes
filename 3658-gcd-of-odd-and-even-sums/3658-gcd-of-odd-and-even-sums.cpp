class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumO= n*n;
        int sumE= n*(n+1);
        while(sumO && sumE){
            if(sumO>sumE){
                sumO-=sumE;
            }else{
                sumE-=sumO;
            }
        }
        return (sumO)? sumO: sumE;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna