class Solution {
public:
    string removeOuterParentheses(string s) {
        int n= s.size();
        int count=0;
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                count++;
                if(count>1){
                    ans+="(";
                }
            }else{
                count--;
                if(count>0){
                    ans+=")";
                }
            }
        }return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna