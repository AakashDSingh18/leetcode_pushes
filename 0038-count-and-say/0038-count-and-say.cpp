class Solution {
public:
    string find_string(string s){
        int n= s.size();
        if(n==0) return "1";
        string ans="";
        int i=0;
        while(i<n){
            int cnt=1;
            while(i<n && s[i]==s[i+1]){
                cnt++;
                i++;
            }
            ans+= (cnt+'0');
            ans+= s[i];
            i++;
        }
        return ans;
    }
    string findall(int m, int& n, string str){
        if(n==1) return "1";
        if(m==n+1) return str;
        str= find_string(str);
        return findall(m+1, n, str);
    }
    string countAndSay(int n) {
        // if(n==1) return "1";
        string str= "";
        return findall(1, n, str);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna