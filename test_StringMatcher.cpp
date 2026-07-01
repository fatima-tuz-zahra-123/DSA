#include <iostream>
#include "StringMatcher.h"

int main() {
    std::cout << "--- STRING PATTERN MATCHING TESTS ---\n";

    // Case 1: Empty pattern
    std::cout << "Empty pattern: " << string_pattern_matching("hello", "") << " (Expected: 0)\n";

    // Case 2: Pattern at the beginning
    std::cout << "Pattern at start: " << string_pattern_matching("labcode", "lab") << " (Expected: 0)\n";

    // Case 3: Pattern at the end
    std::cout << "Pattern at end: " << string_pattern_matching("mainproject", "project") << " (Expected: 4)\n";

    // Case 4: Pattern not present
    std::cout << "Pattern not present: " << string_pattern_matching("computer", "science") << " (Expected: -1)\n";

    return 0;
}