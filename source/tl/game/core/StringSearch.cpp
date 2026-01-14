// StringSearch.cpp
#include "StringSearch.h"

char* FindCharInString(int strStart, char target) {
    char* ptr = reinterpret_cast<char*>(strStart - 1); // start just before the string
    do {
        ptr++;
        if (*ptr == target) {
            return ptr;
        }
    } while (*ptr != '\0'); // keep going until the null terminator
    return nullptr; // not found
}
