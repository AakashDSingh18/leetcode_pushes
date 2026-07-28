class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()<=2) return s;
        priority_queue<char, vector<char>, greater<char>> first_half;
        int i=0;
        int j= s.size()-1;
        while(i<j){
            first_half.push(s[i]);
            i++, j--;
        }
        string ans="";
        while(!first_half.empty()){
            ans+= first_half.top();
            first_half.pop();
        }
        if(s.size() & 1) ans+= s[i];
        j=(s.size()&1)? ans.size()-2: ans.size()-1;
        while(j>=0){
            ans+= ans[j];
            j--;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna