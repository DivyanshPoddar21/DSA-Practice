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