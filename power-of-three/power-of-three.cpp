class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        double num=log(n);
        double den=log(3);
        double ch=num/den;
        if(floor(ch)==ch){
            return true;
        }
        return fabs(round(ch) - ch) < 1e-10;
    }
};