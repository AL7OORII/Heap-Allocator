#include "bump.hpp"

int main() {
    // Create an instance of BumpAllocator with a heap size of 20 * sizeof(int) bytes
    BumpAllocator<20 * sizeof(int)> allocator;

    // Allocate memory for 10 integers
    int* x = allocator.alloc<int>(10);

    // Allocate memory for 10 doubles
    double* y = allocator.alloc<double>(10);

    // Allocate memory for an array of 40 chars (10 * 4)
    char* z = allocator.alloc<char>(40);

    // Check if all allocations were successful
    if (x && y && z) {
        std::cout << "the allocations were successful!" << std::endl;
        // Use the allocated memory here
    }

    // Attempt to allocate memory for 200 integers (this allocation will fail)
    int* w = allocator.alloc<int>(200);

    // Check if the allocation failed as expected
    if (!w) {
        std::cerr << "the allocation failed." << std::endl;
    }

    // Deallocate memory for the array of integers
    allocator.dealloc(x);

    // Deallocate memory for the array of doubles
    allocator.dealloc(y);

    // Memory is not reset until all allocations are deallocated
    // allocator.reset();

    // Return from the program
    return 0;
}
