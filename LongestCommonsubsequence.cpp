#include <iostream> // For input/output operations (e.g., std::cout)
#include <vector>   // For std::vector
#include <string>   // For std::string

// The provided Solution class
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 1. Handle empty input:
        if (strs.empty()) 
            return ""; // If the input array of strings is empty, there's no common prefix.

        // 2. Iterate through the characters of the first string:
        // We assume the first string (strs[0]) as a reference to compare against.
        // The common prefix cannot be longer than the shortest string in the array.
        // By iterating through the first string, we effectively check characters
        // position by position for all strings.
        for (int i = 0; i < strs[0].length(); ++i) { 
            // 'i' represents the current character index we are checking for commonality.

            // 3. Compare the current character with all other strings:
            // For each character at index 'i' in the first string, we compare it
            // with the character at the same index 'i' in all other strings (strs[1] to strs[size-1]).
            for (int j = 1; j < strs.size(); ++j) {
                // 'j' represents the index of the current string being compared with strs[0].

                // 4. Check for two conditions that indicate the end of the common prefix:
                // a) If the current string (strs[j]) is shorter than or equal to the current index 'i':
                //    This means strs[j] doesn't have a character at index 'i' or beyond.
                //    Example: strs = ["flower", "flow", "f"] and i = 1 (checking 'l').
                //    When j points to "f", strs[j].length() is 1, and i is 1.
                //    So, i == strs[j].length() becomes true. The common prefix ends at the previous character.
                // b) If the character at index 'i' in the current string (strs[j][i])
                //    is not equal to the character at index 'i' in the first string (strs[0][i]):
                //    This means we've found a mismatch, and the common prefix ends before this character.
                //    Example: strs = ["flower", "flight"] and i = 2 (checking 'o' vs 'i').
                //    strs[0][2] is 'o', strs[1][2] is 'i'. They don't match.
                //    The common prefix is "fl" (characters up to index i-1).
                if (i == strs[j].length() || strs[j][i] != strs[0][i]) {
                    // If either of these conditions is true, we've found the end of the longest common prefix.
                    // We extract the substring of strs[0] from index 0 up to (but not including) index 'i'.
                    return strs[0].substr(0, i); 
                }
            }
        }

        // 5. If the loop completes:
        // This means that all characters of the first string (strs[0]) were common prefixes
        // for all other strings. In this case, the first string itself is the longest common prefix.
        // This happens if the first string is the shortest and is a prefix of all others.
        // Example: strs = ["apple", "app", "apricot"] -> This solution would return "ap".
        // Example: strs = ["apple", "applepie", "applesauce"] -> This would return "apple".
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
