#ifndef ALGORITHM_TESTING_H
#define ALGORITHM_TESTING_H
#include "Sorting.h"
#include "Search.h"
#include "SimpleTimer.h"
#include <iterator>
class Testing {
private:
    template<typename Container>
    static void PrintContainer(const Container& container);
public:
    template<typename Container>
    static void TestSortingAlgorithms(const Container &original);

    template<typename Container,typename T>
    static void TestSearchAlgorithms(const Container& container,const T& target);
};

template<typename Container>
void Testing::PrintContainer(const Container &container) {
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

template<typename Container>
void Testing::TestSortingAlgorithms(const Container &original) {
    Container container=original;

    std::cout<<"Original: ";
    PrintContainer(container);

    std::cout<<"Bubble Sort: ";
    {
        SimpleTimer tm;
        Sorting::bubble_sort(begin(container), end(container));
    }
    PrintContainer(container);


    std::cout<<"Selection Sort: ";
    container=original;
    {
        SimpleTimer tm;
        Sorting::selection_sort(begin(container), end(container));
    }
    PrintContainer(container);


    std::cout<<"Insertion Sort: ";
    container=original;
    {
        SimpleTimer tm;
        Sorting::insertion_sort(begin(container), end(container));
    }
    PrintContainer(container);


    std::cout<<"Quick Sort: ";
    container=original;
    {
        SimpleTimer tm;
        Sorting::quick_sort(begin(container), end(container));
    }
    PrintContainer(container);



    std::cout<<"Merge Sort: ";
    container=original;
    {
        SimpleTimer tm;
        Sorting::merge_sort(begin(container), end(container));
    }
    PrintContainer(container);

    std::cout<<"Reverse Sort: ";
    container=original;
    {
        SimpleTimer tm;
        Sorting::reverse_sort(std::rbegin(container), std::rend(container));
    }
    PrintContainer(container);
}

template<typename Container, typename T>
void Testing::TestSearchAlgorithms(const Container &container, const T &target) {
    // Test linear search
    std::cout<<"Linear Search: ";
    {
        SimpleTimer tm;
        auto linearResult = Search::linear_search(std::begin(container), std::end(container), target);

    if (linearResult != std::end(container)) {
        std::cout << "Linear Search: Found element in container at index " << std::distance(std::begin(container), linearResult) << std::endl;
    } else {
        std::cout << "Linear Search: Element not found in container" << std::endl;
    }
    }

    // Test binary search
    std::cout<<"Binary Search: ";
    {
        SimpleTimer tm;
        auto binaryResult = Search::binary_search(std::begin(container), std::end(container), target);
        if (binaryResult != std::end(container)) {
            std::cout << "Binary Search: Found element in container at index "
                      << std::distance(std::begin(container), binaryResult) << std::endl;
        } else {
            std::cout << "Binary Search: Element not found in container" << std::endl;
        }
    }

    // Test interpolation search
    std::cout<<"Interpolation Search: ";
    {
        SimpleTimer tm;
        auto interpolationResult = Search::interpolation_search(std::begin(container), std::end(container), target);
        if (interpolationResult != std::end(container)) {
            std::cout << "Interpolation Search: Found element in container at index "
                      << std::distance(std::begin(container), interpolationResult) << std::endl;
        } else {
            std::cout << "Interpolation Search: Element not found in container" << std::endl;
        }
    }
}


#endif //ALGORITHM_TESTING_H
