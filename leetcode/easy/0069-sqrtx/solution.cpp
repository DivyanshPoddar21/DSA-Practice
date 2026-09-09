class Solution {
public:
    int mySqrt(int x) {
        // 1. Handle base cases
        if (x == 0 || x == 1) return x;
        
        // 2. Initialize pointers
        int left = 1;
        int right = x;
        
        // 3. Binary Search
        while (left <= right) {
            // Prevents overflow compared to (left + right) / 2
            int mid = left + (right - left) / 2; 
            
            // Cast to long long to prevent integer overflow during multiplication
            long long square = (long long)mid * mid; 
            
            if (square == x) {
                return mid;
            } else if (square < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // 4. Return the rounded-down nearest integer
        return right; 
    }
};