#include "StringMatcher.h"

int string_pattern_matching(const std::string& text, const std::string& substring) {
    // Edge Case: Empty pattern is always found at index 0
    if (substring.empty()) {
        return 0;
    }

    int n = text.length();
    int m = substring.length();

    // If pattern is longer than text, it can't match
    if (m > n) {
        return -1;
    }

    // Brute force matching window sliding
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != substring[j]) {
                break; // Mismatch found, slide window
            }
        }
        if (j == m) {
            return i; // Full match found
        }
    }

    return -1; 
}