#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Map to store the value and its index
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in our map
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            
            // Otherwise, add the current number and index to the map
            numMap[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no solution is found (though constraints say one always exists)
    }
};