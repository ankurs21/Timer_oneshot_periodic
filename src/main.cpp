#include "Timer.hpp"
#include "Task.hpp"
#include "DataLogger.hpp"
#include <future>
#include <thread>

// Usage example:
int main() {


	Timer periodicTimer, oneShotTimer;

    DataLogger logger;

    Event oneEvent;

    std::cout<<"In Main Thread\n";

    periodicTimer.startPeriodic(2000,1000, [&logger](){

    	logger.logData();
    });

    oneShotTimer.startOneShot(5000, [&oneEvent](){

    	oneEvent.SendEvent();
    });

    std::cout<<"sleep for 20 sec\n";
    // Run for a while
    std::this_thread::sleep_for(std::chrono::seconds(20));

    std::cout<<"After sleep finishes\n";
    // Stop the timers
    oneShotTimer.stop();
    periodicTimer.stop();

    return 0;
}
