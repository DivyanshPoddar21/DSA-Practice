# Longest Common Prefix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

 

 **Example 1:** 

```
Input: strs = ["flower","flow","flight"]
Output: "fl"

```

 **Example 2:** 

```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

```

 

 **Constraints:** 

- 1 <= strs.length <= 200
- 0 <= strs[i].length <= 200
- strs[i] consists of only lowercase English letters if it is non-empty.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 12 MB (beats 39.31%)  
**Submitted:** 2026-09-08T14:38:56.715Z  

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Sort the array of strings
        sort(strs.begin(), strs.end());
        
        // Compare the first and the last string
        string s1 = strs[0];
        string s2 = strs.back();
        int i = 0;
        
        while (i < s1.length() && i < s2.length() && s1[i] == s2[i]) {
            i++;
        }
        
        return s1.substr(0, i);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-common-prefix/)