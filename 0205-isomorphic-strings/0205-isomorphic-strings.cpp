class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int size= s.size();
        int arr1[256]={0};
        int arr2[256]={0};
        for(int i=0; i<size; i++){
            if(arr1[s[i]] != arr2[t[i]]) return false;
            arr1[s[i]]= i+1;
            arr2[t[i]]= i+1;
        }return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna