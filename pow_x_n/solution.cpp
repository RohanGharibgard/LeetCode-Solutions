class Solution {

    double myPowHelper(double x, long n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        }
        double result = 1;
        long currentPow = 0;

        double accumulator = x;
        long accumulatingPow = 1;
        
        while (currentPow != n) {
            if (accumulatingPow * 2 + currentPow  >= n) {
                result *= accumulator;
                currentPow += accumulatingPow;
                accumulatingPow = 1;
                accumulator = x;
            }
            else {
                accumulator *= accumulator;
                accumulatingPow *= 2;
            }
        }

        return result;
    }
public:
    double myPow(double x, int n) {
        if (n < 0) {
            return 1 / myPowHelper(x, -long(n));
        }
        return myPowHelper(x, n);
    }
};
