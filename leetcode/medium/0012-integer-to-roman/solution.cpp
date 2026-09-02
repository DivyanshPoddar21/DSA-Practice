#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        // Define the Roman numeral mappings in descending order
        std::vector<std::pair<int, std::string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        std::string result = "";
        
        // Iterate through the mappings
        for (int i = 0; i < roman.size(); i++) {
            // While the number is large enough, subtract the value and append the symbol
            while (num >= roman[i].first) {
                result += roman[i].second;
                num -= roman[i].first;
            }
        }
        
        return result;
    }
};