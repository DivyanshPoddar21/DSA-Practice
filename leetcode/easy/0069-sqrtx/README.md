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
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.5 MB (beats 87.16%)  
**Submitted:** 2026-09-09T05:31:19.340Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/sqrtx/)