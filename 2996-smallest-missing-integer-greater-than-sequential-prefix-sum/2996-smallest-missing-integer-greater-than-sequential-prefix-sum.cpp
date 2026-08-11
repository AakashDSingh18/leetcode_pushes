class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n= nums.size();
        int sum= nums[0];
        freq[nums[0]]++;
        bool add= true;
        for(int i=1; i<n; i++){
            if(add && nums[i]-1== nums[i-1]){
                sum+= nums[i];
            }else add= false;
            freq[nums[i]]++;
        }
        while(true){
            if(freq.find(sum)== freq.end()) return sum;
            sum++;
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna