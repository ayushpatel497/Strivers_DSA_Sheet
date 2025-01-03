class Solution {
public:
    double myPow(double x, int n) {
        // Q. Pow(x, n)
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        if(n == 0){
            return 1;
        }
        if(n < 0){
            x = 1 / x;
            n = abs(n);
        }
        if(n&1){
            return x * myPow(x, n-1);
        }
        return myPow(x * x, n>>1);
    }
};