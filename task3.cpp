#include <iostream>
#include <chrono>
#include <thread>
#include "bumpup.hpp" 
#include "bumpdown.hpp"  
#include "benchmarks.hpp"

int main() {
    constexpr std::size_t Size = 512; // Size of the memory block

    // Benchmark for BumpAllocatorup
    Benchmark benchmark_up;
    BumpAllocatorup<Size> allocator_up;

    // Start benchmark for BumpAllocatorup
    benchmark_up.start();
    int* ptr_up = allocator_up.alloc<int>(1000); // Example: Allocate a larger block
    benchmark_up.end();

    // Print the elapsed time for BumpAllocatorup
    std::cout << "BumpAllocatorup Time: " << benchmark_up.get_time() << " ms\n";

    // Reset the allocator for the next benchmark
    allocator_up.reset();

    // Benchmark for BumpAllocatordown
    Benchmark benchmark_down;
    BumpAllocatordown<Size> allocator_down;

    // Start benchmark for BumpAllocatordown
    benchmark_down.start();
    int* ptr_down = allocator_down.alloc<int>(1000); // Example: Allocate a larger block
    benchmark_down.end();

    // Print the elapsed time for BumpAllocatordown
    std::cout << "BumpAllocatordown Time: " << benchmark_down.get_time() << " ms\n";

    return 0;
}
