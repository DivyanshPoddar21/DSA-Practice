# Find the Index of the First Occurrence in a String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

 

 **Example 1:** 

```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

```

 **Example 2:** 

```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

```

 

 **Constraints:** 

- 1 <= haystack.length, needle.length <= 104
- haystack and needle consist of only lowercase English characters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.1 MB (beats 74.00%)  
**Submitted:** 2026-09-11T15:50:59.118Z  

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        
        // If needle is longer than haystack, it can't be found
        if (nLen > hLen) return -1;
        
        // Slide the window over haystack
        for (int i = 0; i <= hLen - nLen; i++) {
            int j = 0;
            // Check character by character
            while (j < nLen && haystack[i + j] == needle[j]) {
                j++;
            }
            // If we matched all characters in the needle
            if (j == nLen) {
                return i;
            }
        }
        
        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)