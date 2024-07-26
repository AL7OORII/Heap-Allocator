#include "bump.hpp"
#include <simpletest.h>
using namespace std;

char const* groups[] = {
    "Bump",
};

// Test 1: Allocating memory should succeed
DEFINE_TEST_G(BumpTest1, Bump)
{
    BumpAllocator<20 * sizeof(int)> bumper;

    // Subtest 1: Allocate memory for 3 integers
    int* x = bumper.alloc<int>(3);
    TEST_MESSAGE(x != nullptr, "Subtest 1: Allocate memory for 3 integers.");

    // Subtest 2: Allocate memory for 2 integers
    int* y = bumper.alloc<int>(2);
    TEST_MESSAGE(y != nullptr, "Subtest 2: Allocate memory for 2 integers.");

    // Subtest 3: Allocate memory for 1 integer
    int* z = bumper.alloc<int>(1);
    TEST_MESSAGE(z != nullptr, "Subtest 3: Allocate memory for 1 integer.");
}

// Test 2: Attempt to allocate memory for 30 integers (insufficient space), should fail
DEFINE_TEST_G(BumpTest2, Bump)
{
    BumpAllocator<20 * sizeof(int)> bumper;
    int* y = bumper.alloc<int>(30);
    TEST_MESSAGE(y == nullptr, "Test 2: Attempt to allocate memory for 30 integers (insufficient space).");
}

// Test 3: Deallocate and reallocate memory for 2 integers, should succeed
DEFINE_TEST_G(BumpTest3, Bump)
{
    BumpAllocator<20 * sizeof(int)> bumper;
    int* x = bumper.alloc<int>(3);
    bumper.dealloc(x);
    int* z = bumper.alloc<int>(2);
    TEST_MESSAGE(z != nullptr, "Test 3: Deallocate and reallocate memory for 2 integers.");
}

// Test 4: Allocate memory for 20 chars, should succeed
DEFINE_TEST_G(BumpTest4, Bump)
{
    BumpAllocator<20 * sizeof(char)> bumper;

    // Subtest 4.1: Allocate memory for 20 chars
    char* x = bumper.alloc<char>(20);
    TEST_MESSAGE(x != nullptr, "Subtest 4.1: Allocate memory for 20 chars.");

    // Subtest 4.2: Allocate memory for 10 chars
    char* y = bumper.alloc<char>(10);
    TEST_MESSAGE(y != nullptr, "Subtest 4.2: Allocate memory for 10 chars.");

    // Subtest 4.3: Allocate memory for 5 chars
    char* z = bumper.alloc<char>(5);
    TEST_MESSAGE(z != nullptr, "Subtest 4.3: Allocate memory for 5 chars.");
}

// Test 5: Attempt to allocate memory for 100 chars (insufficient space), should fail
DEFINE_TEST_G(BumpTest5, Bump)
{
    BumpAllocator<20 * sizeof(char)> bumper;
    char* y = bumper.alloc<char>(100);
    TEST_MESSAGE(y == nullptr, "Test 5: Attempt to allocate memory for 100 chars (insufficient space).");
}

// Test 6: Deallocate and reallocate memory for 5 chars, should succeed
DEFINE_TEST_G(BumpTest6, Bump)
{
    BumpAllocator<20 * sizeof(char)> bumper;
    char* x = bumper.alloc<char>(20);
    bumper.dealloc(x);

    // Subtest 6.1: Allocate memory for 5 chars
    char* z = bumper.alloc<char>(5);
    TEST_MESSAGE(z != nullptr, "Subtest 6.1: Deallocate and reallocate memory for 5 chars.");

    // Subtest 6.2: Allocate memory for 15 chars
    char* w = bumper.alloc<char>(15);
    TEST_MESSAGE(w != nullptr, "Subtest 6.2: Allocate memory for 15 chars.");
}

// Test 7: Allocate memory for 4 doubles, should succeed
DEFINE_TEST_G(BumpTest7, Bump)
{
    BumpAllocator<20 * sizeof(double)> bumper;

    // Subtest 7.1: Allocate memory for 4 doubles
    double* x = bumper.alloc<double>(4);
    TEST_MESSAGE(x != nullptr, "Subtest 7.1: Allocate memory for 4 doubles.");

    // Subtest 7.2: Allocate memory for 3 doubles
    double* y = bumper.alloc<double>(3);
    TEST_MESSAGE(y != nullptr, "Subtest 7.2: Allocate memory for 3 doubles.");

    // Subtest 7.3: Allocate memory for 2 doubles
    double* z = bumper.alloc<double>(2);
    TEST_MESSAGE(z != nullptr, "Subtest 7.3: Allocate memory for 2 doubles.");
}

// Test 8: Attempt to allocate memory for 10 doubles (insufficient space), should fail
DEFINE_TEST_G(BumpTest8, Bump)
{
    BumpAllocator<20 * sizeof(double)> bumper;
    double* y = bumper.alloc<double>(10);
    TEST_MESSAGE(y == nullptr, "Test 8: Attempt to allocate memory for 10 doubles (insufficient space).");
}

// Test 9: Deallocate and reallocate memory for 3 doubles, should succeed
DEFINE_TEST_G(BumpTest9, Bump)
{
    BumpAllocator<20 * sizeof(double)> bumper;
    double* x = bumper.alloc<double>(4);
    bumper.dealloc(x);

    // Subtest 9.1: Allocate memory for 3 doubles
    double* z = bumper.alloc<double>(3);
    TEST_MESSAGE(z != nullptr, "Subtest 9.1: Deallocate and reallocate memory for 3 doubles.");

    // Subtest 9.2: Allocate memory for 2 doubles
    double* w = bumper.alloc<double>(2);
    TEST_MESSAGE(w != nullptr, "Subtest 9.2: Allocate memory for 2 doubles.");
}

int main()
{
    bool pass = true;
    for (auto group : groups) {
        pass &= TestFixture::ExecuteTestGroup(group, TestFixture::Verbose);
    }
    return pass ? 0 : 1;
}

