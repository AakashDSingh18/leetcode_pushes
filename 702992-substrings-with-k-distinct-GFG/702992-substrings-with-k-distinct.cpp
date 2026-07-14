class Solution {
  public:
    long long countall(string& s, int k){
        int n= s.size();
        vector<int> freq(26, 0);
        int i=0; 
        int j=0;
        long long count=0;
        int dist=0;
        while(j<n){
            if(freq[s[j]-'a']==0) dist++;
            freq[s[j]-'a']++;
            while(dist>k){
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0) dist--;
                i++;
            }
            count+= (j-i+1);
            j++;
        }
        return count;
    } 
    int countSubstr(string& s, int k) {
        return countall(s, k)-countall(s, k-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna