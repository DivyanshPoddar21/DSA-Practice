#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        // Map each Roman numeral character to its integer value
        std::unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000}
        };
        
        int total = 0;
        
        // Iterate through the characters of the string
        for (int i = 0; i < s.length(); i++) {
            // If the current value is less than the next value, subtract it (e.g., IV, IX)
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i+1]]) {
                total -= roman[s[i]];
            } 
            // Otherwise, just add it to the total
            else {
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};