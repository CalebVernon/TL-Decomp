// GenericSort.h
#pragma once
#include <cstddef>
#include <functional>

using CompareFunc = std::function<int(const void*, const void*)>;

void InsertionSort(void* base, std::size_t count, std::size_t elementSize, CompareFunc cmp);
void QuickSort(void* base, std::size_t count, std::size_t elementSize, CompareFunc cmp);
