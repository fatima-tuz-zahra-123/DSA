#include <iostream>
#include <string>

int string_pattern_matching(std::string text, std::string substring) {
    // Edge Case: Empty pattern. If the pattern is empty, it's technically found at index 0.
    if (substring.empty()) {
        return 0;
    }

    int n = text.length();
    int m = substring.length();

    //the outer loop only needs to go up to (n - m) 
    // because a pattern of length m cannot fit in a remaining text shorter than m.
    for (int i = 0; i <= n - m; i++) {
        int j;
        
        // Check if the substring matches starting at position 'i' of the text
        for (j = 0; j < m; j++) {
            if (text[i + j] != substring[j]) {
                break; // Mismatch found, stop checking this position
            }
        }

        // If the inner loop ran completely through without breaking, we found the match!
        if (j == m) {
            return i; // Return the starting index of the first occurrence
        }
    }

    return -1; // Pattern not present
}

int main() {
    //Case 1: Empty pattern
    std::cout << "Empty pattern: " << string_pattern_matching("hello", "") << "\n";

    //Case 2: Pattern at the beginning
    std::cout << "Pattern at start: " << string_pattern_matching("labcode", "lab") << "\n";

    //Case 3: Pattern at the end
    std::cout << "Pattern at end: " << string_pattern_matching("mainproject", "project") << "\n";

    //Case 4: Pattern not present
    std::cout << "Pattern not present: " << string_pattern_matching("computer", "science") << "\n";

    return 0;
}