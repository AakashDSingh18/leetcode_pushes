class Solution {
public:
    bool sumGame(string num) {
        int n= num.size();
        double r= 0;
        double l= 0;
        int cnt=0;
        for(int i= 0; i<n; i++){
            if(i<n/2){
                if(num[i]=='?'){
                    l+=4.5;
                    cnt++;
                }
                else l+=(num[i]-'0');
            }else{
                if(num[i]=='?'){
                    r+=4.5;
                    cnt++;
                }
                else r+=(num[i]-'0');
            }
        }
        if(cnt&1) return true;
        return !(l-r == 0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna