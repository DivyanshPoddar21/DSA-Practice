class Solution {
public:
    int mySqrt(int x) {
        // Base case
        if (x == 0) return 0;
        
        // Start with x as our initial guess. 
        // We use long to prevent integer overflow when squaring r.
        long r = x;
        
        // Keep averaging as long as r squared is strictly greater than x
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        
        // Once the loop breaks, r * r <= x, so r is our floor square root!
        return r;
    }
};