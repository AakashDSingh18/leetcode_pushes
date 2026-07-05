class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int i=0;
        int k=0;
        int n= s.size();
        int m= t.size();
        if(n>m) return false;
        vector<int> lmatch(n, m);
        vector<int> rmatch(n, -1);
        while(i<n && k<m){
            if(s[i]==t[k]){
                lmatch[i] = k;
                i++ ;
            }
            k++;
        }
        if(i==n) return true;
        int j= n-1;
        k= m-1;
        while(j>=0 && k>=0){
            if(s[j]==t[k]){
                rmatch[j]= k;
                j--;
            }
            k--;
        }
        for(int z= 0; z<n; z++){
            int l= (z==0)? -1: lmatch[z-1];
            int r= (z==n-1)? m: rmatch[z+1];
            if(l!=m && r!=-1 && (r-l)>1) return true;
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna