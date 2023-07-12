class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        for(int i=n-1;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
            }
            else{
                carry=0;
                digits[i]++;
                break;
            }
        }
        if(carry==0){
            return digits;
        }
        reverse(digits.begin(),digits.end());
        digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};