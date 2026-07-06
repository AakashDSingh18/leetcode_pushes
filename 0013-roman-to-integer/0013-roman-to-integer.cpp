class Solution {
public:
    int romanToInt(string s) {
        int size=s.length();
        int num=0;
        int a;
        int last=0;
        for(int i=size-1; i>=0; i--){
            switch(s[i]){
                case('I'):
                    a=1;
                    break;
                case('V'):
                    a=5;
                    break;
                case('X'):
                    a=10;
                    break;
                case('L'):
                    a=50;
                    break;
                case('C'):
                    a=100;
                    break;
                case('D'):
                    a=500;
                    break;
                case('M'):
                    a=1000;
                    break;
            }
            if(a>=last){
                num+=a;
            }else if(a<last){
                num-=a;
            }
            last=a;
        }
        return num;
    }
};






// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna