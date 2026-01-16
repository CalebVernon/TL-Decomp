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
typedef signed char s8;
typedef unsigned char u8;

void strcat_manual(s8* destination, s8* source) {
    s8* var_r1;
    u8 temp_r3;
    s8* var_r2;

    var_r1 = source;
    var_r2 = destination - 1;
    do {
        var_r2 += 1;
    } while (*var_r2 != 0);
    do {
        temp_r3 = (u8) *var_r1;
        var_r1 += 1;
        *var_r2 = temp_r3;
        var_r2 += 1;
    } while (temp_r3 != 0);
}
