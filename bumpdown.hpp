#include <iostream>
#include <cstddef>
#include <cstring>
#include <memory>

using namespace std;

// Bump Allocator class template
template <std::size_t Size>
class BumpAllocatordown {
private:
    char* heap;                  // Pointer to the allocated memory block
    void* next_p;                // Pointer to the next available memory location
    int allocation_counter;      // Counter to keep track of allocations
    std::size_t available_capacity;  // Remaining available memory capacity

public:
    // Constructor: Allocate memory and initialize variables
    BumpAllocatordown() {
        heap = new char[Size];
        allocation_counter = 0;
        next_p = heap + Size;  // Start at the end of the heap
        available_capacity = (std::size_t)Size;
    }

    // Allocate memory for objects of type T
    template <typename T>
    T* alloc(T count) {
        // Check if there is enough available capacity
        if (available_capacity >= sizeof(T) * count) {
            allocation_counter++;
            next_p = (char*)next_p - sizeof(T) * count;
            available_capacity -= sizeof(T) * count;
            return (T*)next_p;
        }

        return nullptr;  // Return nullptr if allocation fails
    }

    // Reset the allocator to the end of the allocated memory
    void reset() {
        next_p = heap + Size;  // Reset to the end of the heap
        allocation_counter = 0;
        available_capacity = (std::size_t)Size;
    }

    // Deallocate memory
    template <typename T>
    void dealloc(T* tmp) {
        allocation_counter--;
        // Reset the allocator only when all allocations have been freed
        if (allocation_counter == 0) {
            reset();
        }
    }
};


