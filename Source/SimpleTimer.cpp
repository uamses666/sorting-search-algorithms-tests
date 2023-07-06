#include "../Header/SimpleTimer.h"
#include <iostream>
SimpleTimer::SimpleTimer() {
    start=std::chrono::high_resolution_clock::now();
}

SimpleTimer::~SimpleTimer() {
    end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration=end-start;
    std::cout<<"duration: "<<duration.count()<<"s"<<std::endl;
}