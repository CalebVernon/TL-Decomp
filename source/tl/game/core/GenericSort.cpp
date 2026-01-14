#include "GenericSort.h"
#include <cstring>   
#include <vector>   

// A super rough “semi-useful” implementation of the weird sorting function
void GenericSort(void* data, void* aux, std::size_t elementSize, CompareFunc cmp) {
    if (!data || !cmp || elementSize == 0) return;

    std::vector<std::pair<uint8_t*, std::size_t>> stack;
    stack.emplace_back(static_cast<uint8_t*>(data), 1); //plchldr

    while (!stack.empty()) {
        auto [base, len] = stack.back();
        stack.pop_back();

        // Skip tiny arrays
        if (len < 11) continue;

        // Pivot selection (middle element)
        uint8_t* pivot = base + (len / 2) * elementSize;
        uint8_t* i = base;
        uint8_t* j = base + (len - 1) * elementSize;

        while (i < j) {
            while (cmp(i, pivot) < 0) i += elementSize;
            while (cmp(j, pivot) > 0) j -= elementSize;

            if (i < j) {
                // Swap aligned if possible, otherwise byte-by-byte
                if ((((uintptr_t)i | (uintptr_t)j | elementSize) & 3) == 0) {
                    uint32_t* pa = reinterpret_cast<uint32_t*>(i);
                    uint32_t* pb = reinterpret_cast<uint32_t*>(j);
                    std::size_t n = elementSize / 4;
                    while (n--) {
                        uint32_t tmp = *pa;
                        *pa++ = *pb;
                        *pb++ = tmp;
                    }
                } else {
                    uint8_t* pa = i;
                    uint8_t* pb = j;
                    std::size_t n = elementSize;
                    while (n--) {
                        uint8_t tmp = *pa;
                        *pa++ = *pb;
                        *pb++ = tmp;
                    }
                }
                i += elementSize;
                j -= elementSize;
            }
        }

        // Push “subarrays” for sorting (roughly, mimicking original stack logic)
        if (i - base > 10) stack.emplace_back(base, i - base);
        if ((base + len * elementSize) - i > 10) stack.emplace_back(i, (base + len * elementSize) - i);
    }
}
