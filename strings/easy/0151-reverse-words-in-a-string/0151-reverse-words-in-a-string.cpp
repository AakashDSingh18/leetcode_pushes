class Solution {
public:
    string reverseWords(string s) {
        int size= s.size();
        int j=size-1;
        string ans;
        for(int i=size-1; i>=0; i--){
            if(s[i]==' '){
                int k=i+1;
                while(k<j+1){
                    if(k==i+1 && ans!="\0") ans+=' ';
                    ans+=s[k];
                    k++;
                }
                j=i-1;
            }
            if(i==0 && j==0 && s[0]!=' '){
                if(ans!="\0") ans+=' ';
                ans+=s[0];
            }
            if(i==0 && i!=j){
                int k=i;
                while(k<j+1){
                    if(k==i && ans!="\0") ans+=' ';
                    ans+=s[k];
                    k++;
                }
            }
        }return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna