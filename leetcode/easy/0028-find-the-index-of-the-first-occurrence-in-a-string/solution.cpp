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