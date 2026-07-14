class Solution {
public:
    int repeatedStringMatch(string a, string b) {
    // Two Pointer:
        int n= a.size();
        int m= b.size();
        if(a==b) return 1;
        int cnt=1;
        string new_a= a;
        int new_n= n;
        while(new_n<m){
            new_a+=a;
            new_n+=n;
            cnt++;
        }
        if(new_a==b) return cnt;
        int i=0, j=0;
        queue<char> target;
        queue<char> curr;
        for(int x=0; x<m; x++) target.push(b[x]);
        while(j<new_n){
            if(curr.size() == m){
                if(curr==target) return cnt;
                curr.pop();
                curr.push(new_a[j]);
            }else{
                curr.push(new_a[j]);
            }
            j++;
        }
        if(curr==target) return cnt;
        new_a+= a;
        new_n+= n;
        cnt++;
        while(j<new_n){
            if(curr==target) return cnt;
            curr.pop();
            curr.push(new_a[j]);
            j++;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna