
#pragma once 

#include <iostream>
#include <functional>

class Event {
public:
    Event() = default;

    // Set the task to be executed after a delay
    void SendEvent() {
        std::cout << "The Event has started" << std::endl;
    }
    
};
