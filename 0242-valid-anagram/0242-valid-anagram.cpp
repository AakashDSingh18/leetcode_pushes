class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char, int> hashmpp;
        int n= s.size();
        for(int i=0; i<n; i++) hashmpp[s[i]]+=1;
        for(int i=0; i<n; i++) hashmpp[t[i]]-=1;
        for(auto x: hashmpp) if(x.second!=0) return false;
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna