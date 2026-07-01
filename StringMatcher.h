#ifndef STRING_MATCHER_H
#define STRING_MATCHER_H

#include <string>

//it finds the first occurrence of a substring in a given text.
//returns the starting index, or -1 if not found.
int string_pattern_matching(const std::string& text, const std::string& substring);

#endif