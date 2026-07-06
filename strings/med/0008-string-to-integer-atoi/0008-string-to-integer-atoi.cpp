class Solution {
public:
    int helper(const string s, int i, long long result, bool posi){
        if(i>=s.size() || !isdigit(s[i])) return ((posi)? (int)result:(int)-1*result);
        result=result*10+(s[i]-'0');
        if (!posi && result>= (long long)-1*INT_MIN) return INT_MIN;
        if (posi &&  result>= INT_MAX) return INT_MAX;
        i++;
        return helper(s, i, result, posi);
    }
    int myAtoi(string s) {
        int i=0;
        long long result=0;
        bool posi=true;
        while(s.size()>i && s[i]==' ') i++;
        if(s.size()>i && (s[i]=='-'||s[i]=='+')){
            posi=(s[i]=='-')? false: true;
            i++;
        }
        return helper(s, i, result, posi);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna