#pragma once
#include <cstdint>
#include <cstddef>

// Comparison function type, like qsort: returns >0 if a > b, 0 if equal, <0 if a < b
using CompareFunc = int(*)(void* a, void* b);

void GenericSort(void* data, void* aux, std::size_t elementSize, CompareFunc cmp);

