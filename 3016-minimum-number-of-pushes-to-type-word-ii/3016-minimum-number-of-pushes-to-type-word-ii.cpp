class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        int n= word.size();
        for(int i=0; i<n; i++) freq[word[i]]++;
        priority_queue<pair<int, char>> q;
        for(auto x: freq) q.push({x.second, x.first});
        int cnt= 0;
        int ans=0;
        while(!q.empty()){
            cnt++;
            if(cnt<=8){
                ans+= q.top().first;
            }else if(cnt<=16){
                ans+= q.top().first * 2;
            }else if(cnt<=24){
                ans+= q.top().first * 3;
            }else{
                ans+= q.top().first * 4;
            }
            q.pop();
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna