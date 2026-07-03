class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        if(start== end) return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, start});
        int n= arr.size();
        vector<int> shortest(1000, INT_MAX);
        while(!q.empty()){
            int curr= q.top().second%1000;
            int step= q.top().first;
            q.pop();
            for(int i=0; i<n; i++){
                int num =(curr*arr[i])%1000;
                if(step+1 < shortest[num]){
                    if(num == end){
                        return step+1;
                    }
                    q.push({step+1, num});
                    shortest[num]= step+1;
                }
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna