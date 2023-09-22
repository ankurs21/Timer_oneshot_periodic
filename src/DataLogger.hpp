
#pragma once 
#include <iostream>
#include <functional>

struct DataLogger {
public:

    DataLogger() = default;

    void logData() {
        static int counter = 1;     
        // Simulate logging sensor data in a real-time system
        std::cout << "Logging sensor data | " << counter++ <<std::endl;
        // In a real scenario, you would log sensor data here.
    }
 
};
