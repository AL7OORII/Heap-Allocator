#include <iostream>
#include <cstddef>
#include <cstring>
#include <memory>

using namespace std;

// Bump Allocator class template
template <std::size_t Size>
class BumpAllocator {
private:
    char* heap;                  // Pointer to the allocated memory block
    void* next_p;                // Pointer to the next available memory location
    int allocation_counter;      // Counter to keep track of allocations
    std::size_t available_capacity;  // Remaining available memory capacity

public:
    // Constructor: Allocate memory and initialize variables
    BumpAllocator() {
        heap = new char[Size];
        allocation_counter = 0;
        next_p = (void*)heap;
        available_capacity = (std::size_t)Size;
    }

    // Allocate memory for objects of type T
    template <typename T>
    T* alloc(std::size_t count = 1) {
        // Attempt to align and allocate memory
        if (std::align(alignof(T), sizeof(T) * count, next_p, available_capacity)) {
            allocation_counter++;
            next_p = (char*)next_p + count * sizeof(T);
            T* result = reinterpret_cast<T*>(next_p);
            return result;
        }
        return nullptr;  // Return nullptr if allocation fails
    }

    // Reset the allocator to the beginning of the allocated memory
    void reset() {
        next_p = heap;
        allocation_counter = 0;
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


