#ifndef ALGORITHM_SEARCH_H
#define ALGORITHM_SEARCH_H
#include "SimpleTimer.h"
#include <algorithm>

class Search {
public:
    template<typename Iterator,typename T>
    static Iterator linear_search(Iterator begin,Iterator end, const T& target);

    template<typename Iterator,typename T>
    static Iterator binary_search(Iterator begin,Iterator end, const T& target);

    template<typename Iterator,typename T>
    static Iterator interpolation_search(Iterator begin,Iterator end, const T& target);
};
template<typename Iterator, typename T>
Iterator Search::linear_search(Iterator begin, Iterator end, const T& target) {
    if(begin==end)
        return end;

    try {
        for (auto it = begin; it != end; ++it) {
            if (*it == target)
                return it;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception occurred during linear search: " << e.what() << std::endl;
    }
    return end;
}

template<typename Iterator, typename T>
Iterator Search::binary_search(Iterator begin, Iterator end, const T& target) {
    if(!std::is_sorted(begin,end) || begin==end)
        return end;

    try {
        auto result = std::lower_bound(begin, end, target);
        if (result != end && *result == target)
            return result;
    } catch (const std::exception& e) {
        std::cout << "Exception occurred during binary search: " << e.what() << std::endl;
    }
    return end;
}

template<typename Iterator, typename T>
Iterator Search::interpolation_search(Iterator begin, Iterator end, const T& target) {
    if(!std::is_sorted(begin,end) || begin==end)
        return end;

    try {
        auto left = begin;
        auto right = end - 1;
        while (left <= right && target >= *left && target <= *right) {
            if (left == right) {
                if (*left == target)
                    return left;
                else
                    return end;
            }
            auto pos = left + ((target - *left) * (right - left)) / (*right - *left);
            if (*pos == target)
                return pos;
            else if (*pos < target)
                left = pos + 1;
            else
                right = pos - 1;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception occurred during interpolation search: " << e.what() << std::endl;
    }
    return end;
}


#endif //ALGORITHM_SEARCH_H
