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


char* StrStr(char* haystack, char* needle)
{
    if (!needle || *needle == '\0')
        return haystack;

    for (; *haystack != '\0'; ++haystack)
    {
        char* h = haystack;
        char* n = needle;

        while (*h != '\0' && *n != '\0' && *h == *n)
        {
            ++h;
            ++n;
        }

        if (*n == '\0')
            return haystack;
    }

    return nullptr;
}
