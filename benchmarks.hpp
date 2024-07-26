#include <chrono>
/* Only needed for the sake of this example. */
#include <iostream>
#include <thread>

// Benchmark class for measuring elapsed time
class Benchmark {
private:
    using time_point = std::chrono::high_resolution_clock::time_point;
    time_point t1;  // Start time point
    time_point t2;  // End time point

public:
    // Constructor: Initialize t1 and t2 with the current time
    Benchmark() {
        t2 = std::chrono::high_resolution_clock::now();
        t1 = std::chrono::high_resolution_clock::now();
    }

    // Start the timer: Set t1 to the current time
    void start() {
        t1 = std::chrono::high_resolution_clock::now();
    }

    // End the timer: Set t2 to the current time
    void end() {
        t2 = std::chrono::high_resolution_clock::now();
    }

    // Calculate and return the elapsed time in milliseconds
    double get_time() {
        using namespace std::chrono;
        duration<double, std::milli> ms_double = t2 - t1;
        return ms_double.count();
    }
};
