#ifndef ALGORITHM_SIMPLETIMER_H
#define ALGORITHM_SIMPLETIMER_H
#include <chrono>

class SimpleTimer {
public:
    SimpleTimer();
    ~SimpleTimer();
private:
    std::chrono::time_point<std::chrono::steady_clock> start, end;
};


#endif //ALGORITHM_SIMPLETIMER_H
