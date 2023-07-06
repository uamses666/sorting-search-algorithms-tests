#ifndef ALGORITHM_SORTING_H
#define ALGORITHM_SORTING_H
#include "SimpleTimer.h"
#include <algorithm>
#include <iostream>
class Sorting {
public:
    template<typename Iterator>
    static void bubble_sort(Iterator begin, Iterator end);

    template<typename Iterator>
    static void selection_sort(Iterator begin, Iterator end);

    template<typename Iterator>
    static void insertion_sort(Iterator begin, Iterator end);

    template<typename Iterator>
    static void quick_sort(Iterator begin, Iterator end);

    template<typename Iterator>
    static void merge_sort(Iterator begin, Iterator end);

};
template<typename Iterator>
void Sorting::bubble_sort(Iterator begin, Iterator end) {
    if (begin == end || std::next(begin) == end || std::is_sorted(begin,end))
        return;

    try {
        for (auto it = begin; it != end - 1; ++it) {
            for (auto it2 = it + 1; it2 != end; ++it2) {
                if (*it > *it2)
                    std::iter_swap(it, it2);
            }
        }
    } catch (const std::exception& e) {
        std::cout << "Exception occurred during bubble sort: " << e.what() << std::endl;
    }
}

template<typename Iterator>
void Sorting::selection_sort(Iterator begin, Iterator end) {
    if (begin == end || std::next(begin) == end || std::is_sorted(begin,end))
        return;

    try {
        for (auto it = begin; it != end; ++it) {
            auto min_it = it;
            for (auto it2 = it; it2 != end; ++it2) {
                if (*it2 < *min_it) {
                    min_it = it2;
                }
            }
            std::swap(*it, *min_it);
        }
    } catch (const std::exception& e) {
        std::cout << "Exception occurred during selection sort: " << e.what() << std::endl;
    }
}

template<typename Iterator>
void Sorting::insertion_sort(Iterator begin, Iterator end) {
    if (begin == end || std::next(begin) == end || std::is_sorted(begin,end))
        return;

    try {
        for (auto it = begin; it != end; ++it) {
            auto key = *it;
            auto j = it;
            while (j != begin && *(j - 1) > key) {
                *j = *(j - 1);
                j--;
            }
            *j = key;
        }
    }    catch (const std::exception& e) {
        std::cout << "Exception occurred during insertion sort: " << e.what() << std::endl;
    }
}

template<typename Iterator>
void Sorting::quick_sort(Iterator begin, Iterator end) {
    if (begin == end || std::next(begin) == end || std::is_sorted(begin,end))
        return;

    try {
        auto pivot = *std::prev(end);
        auto split = std::partition(begin, std::prev(end),
                                    [pivot](const auto& element) { return element < pivot; });
        std::iter_swap(split, std::prev(end));
        quick_sort(begin, split);
        quick_sort(std::next(split), end);
    } catch (const std::exception& e) {
        std::cout << "Exception occurred during quick sort: " << e.what() << std::endl;
    }
}

template<typename Iterator>
void Sorting::merge_sort(Iterator begin, Iterator end) {
    if (std::distance(begin, end) <= 1 || std::is_sorted(begin,end))
        return;

    try {
        auto mid = std::next(begin, std::distance(begin, end) / 2);
        merge_sort(begin, mid);
        merge_sort(mid, end);
        std::inplace_merge(begin, mid, end);
    } catch (const std::exception& e) {
        std::cout << "Exception occurred during merge sort: " << e.what() << std::endl;
    }
}




#endif //ALGORITHM_SORTING_H
