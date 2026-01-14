// GenericSort.cpp
#include "GenericSort.h"
#include <cstring>
#include <cstdint>
void InsertionSort(void* base, std::size_t count, std::size_t elementSize, CompareFunc cmp) {
    uint8_t* arr = static_cast<uint8_t*>(base);
    for (size_t i = 1; i < count; i++) {
        uint8_t* key = arr + i * elementSize;
        size_t j = i;
        while (j > 0 && cmp(arr + (j-1)*elementSize, key) > 0) {
            std::memcpy(arr + j*elementSize, arr + (j-1)*elementSize, elementSize);
            j--;
        }
        if (j != i)
            std::memcpy(arr + j*elementSize, key, elementSize);
    }
}

void QuickSort(void* base, std::size_t count, std::size_t elementSize, CompareFunc cmp) {
    if (count <= 10) {
        InsertionSort(base, count, elementSize, cmp);
        return;
    }

    uint8_t* stack[64];
    size_t sizes[64];
    int top = 0;
    stack[top] = static_cast<uint8_t*>(base);
    sizes[top] = count;
    top++;

    while (top > 0) {
        top--;
        uint8_t* arr = stack[top];
        size_t n = sizes[top];

        if (n <= 10) {
            InsertionSort(arr, n, elementSize, cmp);
            continue;
        }

        size_t pivotIndex = n / 2;
        uint8_t* pivot = arr + pivotIndex * elementSize;

        size_t i = 0, j = n-1;
        while (i <= j) {
            while (cmp(arr + i*elementSize, pivot) < 0) i++;
            while (cmp(arr + j*elementSize, pivot) > 0) j--;
            if (i <= j) {
                uint8_t tmp[256]; // max element size 256 bytes
                std::memcpy(tmp, arr + i*elementSize, elementSize);
                std::memcpy(arr + i*elementSize, arr + j*elementSize, elementSize);
                std::memcpy(arr + j*elementSize, tmp, elementSize);
                i++; j--;
            }
        }

        if (i < n) {
            stack[top] = arr + i*elementSize;
            sizes[top] = n - i;
            top++;
        }
        if (j > 0) {
            stack[top] = arr;
            sizes[top] = j + 1;
            top++;
        }
    }
}
