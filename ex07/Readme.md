# Exercise Sheet 7

In this exercise sheet you will continue to use POSIX threads and test different methods for mutual exclusion and synchronization.

# Task 1

Implement a single producer multiple consumer pattern as requested in Exercise Sheet 6 Task 2 ([link](../ex06/Readme.md)), but use `pthread_spinlock` to protect queue access. What are the advantages and disadvantages compared to `pthread_mutex`?

Measure the execution time with `/usr/bin/time -v [executable]`, compare it to the execution time of last week's task and interpret the results.

# Task 2

Repeat Task 1 (including the execution time measurement and interpretation), but use pthread condition variables to signal the availability of new elements. What are the advantages and disadvantages compared to the other two approaches?
