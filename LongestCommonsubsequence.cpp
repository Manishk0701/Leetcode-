#include <iostream> // For input/output operations (e.g., std::cout)
#include <vector>   // For std::vector
#include <string>   // For std::string

// The provided Solution class
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty())
            return "";

        for (int i = 0; i < strs[0].length(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (i == strs[j].length() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

// Main function to test the Solution
int main() {
    Solution sol;

    // Example 1:
    std::vector<std::string> strs1 = {"flower", "flow", "flight"};
    std::cout << "Longest Common Prefix for {\"flower\", \"flow\", \"flight\"}: "
              << sol.longestCommonPrefix(strs1) << std::endl; // Expected: fl

    // Example 2:
    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    std::cout << "Longest Common Prefix for {\"dog\", \"racecar\", \"car\"}: "
              << sol.longestCommonPrefix(strs2) << std::endl; // Expected: ""

    // Example 3: Single string
    std::vector<std::string> strs3 = {"apple"};
    std::cout << "Longest Common Prefix for {\"apple\"}: "
              << sol.longestCommonPrefix(strs3) << std::endl; // Expected: apple

    // Example 4: Empty vector
    std::vector<std::string> strs4 = {};
    std::cout << "Longest Common Prefix for {}: "
              << sol.longestCommonPrefix(strs4) << std::endl; // Expected: ""

    // Example 5: No common prefix, but all start with different letters
    std::vector<std::string> strs5 = {"abc", "def", "ghi"};
    std::cout << "Longest Common Prefix for {\"abc\", \"def\", \"ghi\"}: "
              << sol.longestCommonPrefix(strs5) << std::endl; // Expected: ""

    // Example 6: Common prefix is the first string
    std::vector<std::string> strs6 = {"apple", "applepie", "applesauce"};
    std::cout << "Longest Common Prefix for {\"apple\", \"applepie\", \"applesauce\"}: "
              << sol.longestCommonPrefix(strs6) << std::endl; // Expected: apple

    return 0; // Indicate successful execution
}