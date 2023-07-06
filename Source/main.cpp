#include "../Header/Testing.h"
#include <vector>
#include <deque>
#include <array>
#include <random>
int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1,1000);

    std::vector<int> vec={12,124,51,6,3,0,523,5,23,5,1};
    Testing::TestSortingAlgorithms(vec);
    Sorting::bubble_sort(vec.begin(),vec.end());
    Testing::TestSearchAlgorithms(vec,124);

    std::deque<int> dq={12,124,51,6,3,0,523,5,23,5,1};
    Testing::TestSortingAlgorithms(dq);
    Sorting::quick_sort(dq.begin(),dq.end());
    Testing::TestSearchAlgorithms(dq,523);
    Testing::TestSearchAlgorithms(dq,1251251);

    std::array<int,11> arr={12,124,51,6,3,0,523,5,23,5,1};
    Testing::TestSortingAlgorithms(arr);
    Sorting::merge_sort(arr.begin(),arr.end());
    Testing::TestSearchAlgorithms(arr,51);

    std::string str="the quick brown fox jumps over the lazy dog";
    Testing::TestSortingAlgorithms(str);
    Sorting::bubble_sort(str.begin(),str.end());
    Testing::TestSearchAlgorithms(str,'z');

    std::vector<int> largeVec(10000);
    std::generate(largeVec.begin(),largeVec.end(),[&](){return dist(gen);});
    Testing::TestSortingAlgorithms(largeVec);
    Sorting::bubble_sort(largeVec.begin(),largeVec.end());
    Testing::TestSearchAlgorithms(largeVec,999);

    std::vector<char> chVec={'a','c','d','i','b','w','8','n','0','p','i','i'};
    Testing::TestSortingAlgorithms(chVec);
    Sorting::selection_sort(chVec.begin(),chVec.end());
    Testing::TestSearchAlgorithms(chVec,'w');

    std::vector<double> doubleVec={12.54,0.8,99.99,100.67,1.5,-21,-0.89,-100.920024};
    Testing::TestSortingAlgorithms(doubleVec);
    Sorting::quick_sort(doubleVec.begin(),doubleVec.end());
    Testing::TestSearchAlgorithms(doubleVec,99.99);

    std::vector<int> emptyVec;
    Testing::TestSortingAlgorithms(emptyVec);
    Testing::TestSearchAlgorithms(emptyVec,11);

    std::vector<int> smallVec={2,1};
    Testing::TestSortingAlgorithms(smallVec);

    return 0;
}
