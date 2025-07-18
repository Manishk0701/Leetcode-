#include <iostream> // Required for std::cout and std::endl
#include <string>   // Required for std::string
#include <algorithm> // Required for std::reverse
#include <vector>   // Not strictly needed for this problem, but often useful

// The Solution class provided
class Solution {
public:
    std::string reverseWords(std::string s) {
        int n = s.length();
        std::string ans = "";

        // Reverse the entire string
        std::reverse(s.begin(), s.end());

        // Iterate through the reversed string to extract and reverse words
        for (int i = 0; i < n; ) { // No i++ here, done inside loops
            // Skip leading spaces before a word
            while (i < n && s[i] == ' ') {
                i++;
            }

            // If we've reached the end of the string after skipping spaces, break
            if (i == n) {
                break;
            }

            std::string word = ""; // Initialize string for the current word
            int word_start = i;    // Mark the beginning of the word

            // Extract the current word
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Reverse the extracted word
            std::reverse(word.begin(), word.end());

            // Append the reversed word to the answer string
            // We append a space ONLY if it's not the first word being added
            if (ans.empty()) {
                ans += word;
            } else {
                ans += " " + word;
            }
        }
        
        // No need for substr(1) if spaces are handled correctly during appending
        return ans;
    }
};

// Main function to test the Solution class
int main() {
    Solution sol;

    // Test Cases
    std::string s1 = "the sky is blue";
    std::cout << "Input: \"" << s1 << "\"" << std::endl;
    std::cout << "Output: \"" << sol.reverseWords(s1) << "\"" << std::endl; // Expected: "blue is sky the"
    std::cout << "--------------------" << std::endl;

    std::string s2 = "  hello world  ";
    std::cout << "Input: \"" << s2 << "\"" << std::endl;
    std::cout << "Output: \"" << sol.reverseWords(s2) << "\"" << std::endl; // Expected: "world hello"
    std::cout << "--------------------" << std::endl;

    std::string s3 = "a good   example";
    std::cout << "Input: \"" << s3 << "\"" << std::endl;
    std::cout << "Output: \"" << sol.reverseWords(s3) << "\"" << std::endl; // Expected: "example good a"
    std::cout << "--------------------" << std::endl;

    std::string s4 = "single";
    std::cout << "Input: \"" << s4 << "\"" << std::endl;
    std::cout << "Output: \"" << sol.reverseWords(s4) << "\"" << std::endl; // Expected: "single"
    std::cout << "--------------------" << std::endl;

    std::string s5 = "   ";
    std::cout << "Input: \"" << s5 << "\"" << std::endl;
    std::cout << "Output: \"" << sol.reverseWords(s5) << "\"" << std::endl; // Expected: ""
    std::cout << "--------------------" << std::endl;

    return 0; // Indicate successful execution
}