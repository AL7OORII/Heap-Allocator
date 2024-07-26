# Heap-Allocator

This repository contains the solution for the Heap Allocator assignment, consisting of three tasks.

Task 1: Implement a Heap Allocator

Files


bump.hpp: Implementation of the Bump Allocator class template.

Task1.cpp: Usage example of the Bump Allocator.


Instructions

The bump.hpp file contains the implementation of a Bump Allocator class template.
The Task1.cpp file demonstrates how to use the Bump Allocator to allocate and deallocate memory.

Usage
To compile and run the c++ program, we can use the following code line (C++ compiler):
run task1:
clang++ -o task1 task1.cpp
./task1



Task 2: Write Unit Tests

Files


task2.cpp: Unit tests using the SimpleTest framework.


Instructions


task2.cpp contains unit tests for the Bump Allocator implemented in Task 1.
Use the SimpleTest framework to run the tests and ensure the allocator behaves as expected.

Usage
To compile and run the c++ program, we can use the following code line (C++ compiler):
run task 2:
clang++ -I simpletest -o task2 task2.cpp simpletest/simpletest.cpp
./task2



Task 3: Design and Implement a Benchmark

Files


benchmarks.hpp: Benchmark class for measuring elapsed time.

bumpup.hpp and bumpdown.hpp: Implementations of Bump Allocators that bump up and down, respectively.

task3.cpp: Benchmarking the Bump Allocators.


Instructions


benchmarks.hpp contains a Benchmark class for measuring elapsed time.

bumpup.hpp and bumpdown.hpp provide two versions of the Bump Allocator that bump up and down.

task3.cpp benchmarks the Bump Allocators and reports the time taken for allocation.
Optimize the Bump Allocator to always bump down and re-run the benchmark.

Usage
To compile and run the c++ program, we can use the following code line (C++ compiler):
clang++ -o task3 task3.cpp
./task3

run unit test for task 3:
clang++ -I simpletest -o unittest3 unittest3.cpp simpletest/simpletest.cpp
./unittest3
