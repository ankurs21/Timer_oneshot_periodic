#include "Timer.hpp"

#include <thread>
#include <chrono>

// Start a one-shot timer with a given delay and a callback
void Timer::startOneShot(unsigned int delayMs, std::function<void()> callback) {
    if (!is_running) {
        is_running = true;
        std::thread([this, callback, delayMs]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
            callback();
            is_running = false;
        }).detach();
    }    
}


// Start a periodic timer with a given period and a callback
void Timer::startPeriodic(unsigned int delayMs,unsigned int periodMs, std::function<void()> callback) {
    if (!is_running) {
        is_running = true;
        std::thread([this, callback, delayMs, periodMs]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
            while (is_running) {
                callback();
                std::this_thread::sleep_for(std::chrono::milliseconds(periodMs));
            }
        }).detach();
    }
}


//Stop the timer
void Timer::stop() {
    std::cout<<"Stop Timer\n";
    is_running = false;
}


