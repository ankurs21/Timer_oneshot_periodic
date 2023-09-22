

#pragma once 

#include <iostream>
#include <functional>

#include <atomic>

class Timer {
public:
    Timer() : is_running(false) {}

    // Start a one-shot timer with a given delay and a callback
    void startOneShot(unsigned int delayMs, std::function<void()> callback) ;

    // Start a periodic timer with a given period and a callback
    void startPeriodic(unsigned int delayMs, unsigned int periodMs, std::function<void()> callback) ;

    // Stop the timer
    void stop() ;

private:
    std::atomic<bool> is_running;
};



