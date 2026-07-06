class Solution {
public:
    string longestPalindrome(string s) {
        int size= s.size();
        string ans="";
        ans+=s[0];
        int size_ans=0;
        for(int i=0; i<size; i++){
            int left= i-1;
            int right= i+1;
            while(right<size && left>=0 && s[left]==s[right]){
                if(size_ans<right-left+1){
                    size_ans=right-left+1;
                    ans=s.substr(left, right-left+1);
                }left--,right++;
            }

            int left2= i;
            int right2= i+1;
            while(right2<size && left2>=0 && s[left2]==s[right2]){
                if(size_ans<right2-left2+1){
                    size_ans=right2-left2+1;
                    ans=s.substr(left2, right2-left2+1);
                }left2--,right2++;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna