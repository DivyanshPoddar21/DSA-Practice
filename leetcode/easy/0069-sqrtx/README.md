# Sqrt(x)

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a non-negative integer `x`, return  *the square root of* `x` *rounded down to the nearest integer*. The returned integer should be  **non-negative**  as well.

You  **must not use**  any built-in exponent function or operator.

- For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 

 **Example 1:** 

```
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

```

 **Example 2:** 

```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

```

 

 **Constraints:** 

- 0 <= x <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 20.64%)  
**Memory:** 8.6 MB (beats 14.29%)  
**Submitted:** 2026-09-09T05:30:52.386Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/sqrtx/)