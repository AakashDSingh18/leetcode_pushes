class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> track;
        int cnt=0;
        int n= s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='(') track.push(s[i]);
            else{
                if(track.empty()) cnt++;
                else track.pop();
            }
        }
        cnt+= track.size();
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna