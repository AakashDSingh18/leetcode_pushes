class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mapp;
        mapp[1]= "I";
        mapp[4]= "IV";
        mapp[5]= "V";
        mapp[9]= "IX";
        mapp[10]= "X";
        mapp[40]= "XL";
        mapp[50]= "L";
        mapp[90]= "XC";
        mapp[100]= "C";
        mapp[400]= "CD";
        mapp[500]= "D";
        mapp[900]= "CM";
        mapp[1000]= "M";
        string ans="";
        int temp;
        while(num){
            if(num-1000 >= 0){
                ans+= mapp[1000];
                num-=1000;
            }else if(num-500 >= 0){
                // temp= num/500;
                if(num>=900){
                    ans+= mapp[900];
                    num-= 900;
                    continue;
                }
                ans+= mapp[500];
                num-= 500;
            }else if(num-100 >= 0){
                temp= num/100;
                if(temp>3){
                    num%= 100;
                    ans+= mapp[400];
                    continue;
                }
                else ans+= mapp[100];
                num-= 100;
            }else if(num-50 >= 0){
                // temp= num/50;
                if(num>=90){
                    ans+= mapp[90];
                    num-= 90;
                    continue;
                }
                ans+= mapp[50];
                num-= 50;
            }else if(num-10 >= 0){
                temp= num/10;
                if(temp>3){
                    num%=10;
                    ans+= mapp[40];
                    continue;
                }
                else ans+= mapp[10];
                num-= 10;
            }else if(num-5 >= 0){
                // temp= num/5;
                if(num==9){
                    ans+= mapp[9];
                    num=0;
                    continue;
                }
                ans+= mapp[5];
                num-= 5;
            }else if(num-1 >= 0){
                temp= num/1;
                if(temp>3){
                    num%=1;
                    ans+= mapp[4];
                    continue;
                }
                else ans+= mapp[1];
                num-= 1;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna