class Solution {
public:
    int minOperations(string s1, string s2) {
        int n= s1.size();
        if(s1[0]=='1' && s2[0]=='0' && n==1) return -1;
        int cnt=0;
        int i=0;
        while(i<n){
            if(s1[i]=='0' && s1[i]!=s2[i]){
                s1[i]='1';
                cnt++;
            }else if(s1[i]=='1' && s1[i]!=s2[i]){
                if(i+1<n && s1[i+1]=='1' && s1[i+1]!=s2[i+1]){
                    s1[i]='0';
                    s1[i+1]='0';
                    cnt++, i++;
                }else{
                    s1[i]='0';
                    cnt+=2;
                }
            }
            i++;
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna