# Exercise Sheet 10

In this exercise sheet you will continue to use POSIX threads and perform different types of memory management within them.

# Task 1

Implement a free list allocator (see lecture slides) which uses free lists for requests up to 2^16 Bytes (one separate free list for each power of 2). Again, create one version that uses a global set of free lists with access locks, and another which uses a separate allocator for each thread. Compare their performance as in the previous exercise sheet.

# Task 2

Use `membench` to compare all 4 of your allocators as well as the default allocator on the system. Perform your comparisons acrosss 1, 2, 4 and 8 threads, and for allocations of 2^N Bytes for N=4...22.
